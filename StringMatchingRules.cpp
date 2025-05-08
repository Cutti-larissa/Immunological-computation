#include <bits/stdc++.h> //edit distance, only works on gcc, muito grande(tentar retirar)
#include <vector>
#include <math.h>
#include <stdlib.h> //landscape diff
#include "StringMatchingRules.hpp"

//----------------------------------------------------------------------------------------------------------------------------------------------
//HammingDistance -> número de diferentes caracteres entre duas strings
size_t HammingDistance(const string& x, const string& y){ //Tratar casos em que a string é digitada pelo usuário
    size_t result{0};
    size_t length = x.size();
    for(size_t i = 0; i < length; ++i){
        result += (x[i] ^ y[i]);
    }
    return result;
}
//----------------------------------------------------------------------------------------------------------------------------------------------
//Binary  distance

//número de 1's que match nas duas strings
size_t BDa(const string& x, const string& y){
    size_t result{0};
    size_t length = x.size();
    for(size_t i = 0; i < length; ++i){
        if((x[i] == 1) && (y[i] == 1))
            result++;
    }
    return result;
}

//número de 1's na string x que não match na string y
size_t BDb(const string& x, const string& y){
    size_t result{0};
    size_t length = x.size();
    for(size_t i = 0; i < length; ++i){
        if((x[i] == 1) && (y[i] == 0))
            result++;
    }
    return result;
}

//número de 0's na string x que não match na string y
size_t BDc(const string& x, const string& y){
    size_t result{0};
    size_t length = x.size();
    for(size_t i = 0; i < length; ++i){
        if((x[i] == 0) && (y[i] == 1))
            result++;
    }
    return result;
}

//número de 0's que match nas duas strings
size_t BDd(const string& x, const string& y){ 
    size_t result{0};
    size_t length = x.size();
    for(size_t i = 0; i < length; ++i){
        if((x[i] == 0) && (y[i] == 0))
            result++;
    }
    return result;
}

double RusselRao(const size_t a, const size_t b, const size_t c, const size_t d){ //talvez só um return direto
    double f;
    f = (a / (a + b + c + d));
    return f;
}

double JacardNeedham(const size_t a, const size_t b, const size_t c){
    double f;
    f = (a / (a + b + c));
    return f;
}

double Kulzinski(const size_t a, const size_t b, const size_t c){
    double f;
    f = (a / (b + c + 1));
    return f;
}

double SokalMichener(const size_t a, const size_t b, const size_t c, const size_t d){
    double f;
    f = ((a + d) / (a + b + c + d));
    return f;
}

double RogersTanimoto(const size_t a, const size_t b, const size_t c, const size_t d){
    double f;
    f = ((a + d) / (a + d + (2 * (b + c))));
    return f;
}

double Yule(const size_t a, const size_t b, const size_t c, const size_t d){
    double f;
    f = (((a * d) - (b * c)) / ((a * d) + (b * c)));
    return f;
}
//----------------------------------------------------------------------------------------------------------------------------------------------
//Edit/Levenshtein distance - número minímo de transformações na string necessárias para transformar s(x) em y(x)
//ideia retirada do site geekforgeeks, verificar tipos
//Possui versão recursiva e mais de uma interativa (versão escolhida aparenta ser a mais eficiente)
size_t editDistance(const string& x, const string& y){
    size_t xl = x.size();
    size_t yl = y.size();

    int prev; //verficar
    std::vector<int> curr(yl + 1, 0);

    for(int j = 0; j <= yl; ++j)
        curr[j] = j;

    for(int i = 1; i <= xl; ++i){
        prev = curr[0];
        curr[0] = 1;
        for(int j = 1; j <= yl; ++j){
            int temp = curr[j];
            if(x[i - 1] == y[j - 1])
                curr[j] = prev;
            else
                curr[j] = 1 + std::min({curr[j - 1], prev, curr[j]});
            prev = temp;
        }
    }
    return curr[yl];
}
//------------------------------------------------------------------------------------------------------------------------------------------------
//Value Difference Metric

//A probabilidade de uma letra pertencer a um alfabeto é de uma entre o tamanho do alfabeto
//Probabilidade de VDM definido em outro artigo -> soma do número de intancias em um set de treino que tem o valor x para um atributo i e um output c para todas as classes c's
double P(const size_t length){
    double p;
    p = (1 / length); //por outro artigo
    //aqui seria (número de instâncias em um set de treino que tem o valor x para um atributo a e um output c definido)/(soma do número de instâncias de um set de treino que tem o valor x para um atributo i e um output c para todos os c's em C)
    return p;
}

//no artigo o vdm seria apenas essa parte
size_t vdm(const char xi, const char yi, const size_t length){
    size_t count{0};
    for(size_t c = 0; c < length; ++c)
        count += pow((P(length) - P(length)), 2); //sempre resulta 0, arrumar, pelo artigo aqui nem sempre resultaria 0
    return count;
}

size_t weight(const char xi, const string& C, const size_t length){
    size_t somatorio{0};
    for (size_t i = 0; i < length; ++i)
        somatorio += pow(P(length), 2);

    return = sqrt(somatorio);
}
size_t valueDifferenceMetric(const string& x, const string& y, const string& alfabeto){
    size_t count{0};
    size_t length = x.size();
    for(size_t i = 0; i < length; ++i)
        count += (vdm(x[i], y[i], alfabeto) * weight(x[i], alfabeto)); //verificar se chamar a função assim funciona ou é melhor colocar em variáveis
    return count;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//Landscape-Affinity Matching - input e anticorpo strings são dadas como amostras de bytes e então convertidas em valores inteiros positivos para gerar um landscape e então duas strings são comparadas usando uma sliding window
size_t diffMatching(const string& x, const string& y, const size_t N){
    size_t count{0};
    for(size_t i = 0; i < N; ++i)
        count += abs(x[i] - y[i]);
    return count;
}   

size_t slopeMatching(const string& x, const string& y, const size_t N){
    size_t count{0};
    for(size_t i = 0; i < N; ++i){
        size_t s1 = (x[i+1] - x[i]);
        size_t s2 = (y[i+1] - y[i]);
        count += abs(s1 - s2);
    }
    return count;
}

size_t physicalMatching(const string& x, const string& y, const size_t N, const int mi){ //o que é o mi?
    size_t soma{0}, dif, sub{0}, mini{0};
    dif = x[0] - y[0];
    for(size_t i = 0; i < N; ++i){
        sub = (x[i] - y[i]);
        mini = std::min(sub, dif);
        soma += (x[i+1] - y[i]) + 3*mi*mini;
        if(dif > sub)
            dif = sub;
    }
    return soma;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//R-contigous bits matching
//os bits são iguais nas mesmas posições
unsigned short rcb(const std::string& x, const std::string& y, const size_t length, const size_t r){
    size_t m{0};
    size_t maiorM{0};
    for(int i = 0; i < length; ++i){
        if (x[i] == y[i]){
            m++;
            if (m > maiorM)
                maiorM = m; //talvez usar essa parametro para comparação de maior match entre duas strings
        }else 
            t = 0;
        if (m == r)
            return 1; //verdadeiro, as strings match em um size r
    }
    return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//R-Chunk Matching Rule - generalização do rcb
//não precisa ser na mesma posição
short rcmr(const string& x, const string& y, const size_t length, const size_t r){
    size_t t{0};
    size_t maiorM{0};
    for(int i = 0; i < length; ++i){
        for (int j = 1; j < r; j++){
            if (x[i] == y[i]){

            }
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//Real Valued Vector Matching Rule
size_t euclidianDistance(const std::vector<size_t> x, const std::vector<size_t> y, const size_t length){
    size_t dist{0}, sub{0};
    for(int i = 0; i < length; ++i){
        sub = (x[i] - y[i]);
        dist += pow(sub, 2);
    }
    dist = sqrt(dist);
    return dist;
}

size_t paticialED(const std::vector<size_t> x, const std::vector<size_t> y, const size_t length, const size_t w){
    size_t dist{0}, sub{0};
    for(int i = 0; i < w; ++i){
        if(i >= length){
            //exception acabou string
            return -1;
        }
        sub = (x[i] - y[i]);
        dist += pow(sub, 2);
    }
    return dist;
}

size_t minkowskiDistance(const std::vector<size_t> x, const std::vector<size_t> y, const size_t length, const size_t l){
    size_t dist{0}, sub{0};
    for(int i = 0; i < length; ++i){
        sub = abs(x[i] - y[i]);
        dist += pow(sub, l);
    }
    dist = pow(dist, (1/l));
    return dist;
}

size_t chebyshevDistance(const std::vector<size_t> x, const std::vector<size_t> y, const size_t length){
    size_t dist{0}, sub{0};
    for (int i = 0; i < length; ++i){
        sub = x[i] - y[i];
        if (sub > dist)
            dist = sub;
    }
    return dist;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//Mixed representation

//Heterogeneous Euclidian-Overlap Metric

//Hamming distance definido como x=y -> 0, else 1
unsigned short overlap(const size_t xi, const size_t yi){
    if (xi == yi)
        return 0;
    return 1;
}

size_t heom(const size_t xi, const size_t yi, const size_t rangei){ //range = fator de escala para a iésima váriavel contínua
    unsigned short categorico; //o que é uma variavel ser categórica ou real? 
    size_t retorno{0}, sub{0};
    if(categorico)
        retorno = overlap(xi,yi);
    else{
        sub = abs(xi - yi);
        retorno = sub / rangei;
    }
    return retorno;
}

size_t HEOM(const std::vector<size_t> x, const std::vector<size_t> y, const size_t N){
    size_t dist{0}, heom{0}, rangei{1}; //verificar o que é o rangei
    for(int i = 0; i < N; ++i){
        heom = heom(x[i], y[i], rangei);
        dist += pow(heom, 2);
    }
    dist = sqrt(dist);
    return dist; 
}

//Heterogeneous Value Difference Metric

size_t hvdm(const size_t xi, const size_t yi, const size_t rangei){
    unsigned short categorico; //o que é uma variavel ser categórica ou real? 
    size_t retorno{0}, sub{0};
    if(categorico)
        retorno = sqrt(vdm(xi, yi, 1)); //vdm recebe parametro char, talvez seja necessário fazer algumas modificações
    else{
        sub = abs(xi - yi);
        retorno = sub / rangei;
    }
    return retorno;
}

size_t HVDM(const std::vector<size_t> x, const std::vector<size_t> y, const size_t N){
    size_t dist{0}, hvdm{0}, rangei{1}; //o que é rangei?
    for(int i = 0; i < N; ++i){
        hvdm = hvdm(x[i], y[i]);
        dist += pow(hvdm, 2);
    }
    dist = sqrt(dist);
    return dist; 
}
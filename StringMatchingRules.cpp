//#include <bits/stdc++.h> //edit distance, onlu works on gcc, muito grande(tentar retirar)
//#include <vector>
//#include <math.h>
//#include <stdlib.h> //landscape diff

//número de diferentes caracteres entre duas strings
size_t HammingDistance(const string& x, const string& y){ 
    size_t result{0};
    size_t length = x.size();
    for(size_t i = 0; i < length; ++i){
        result += (x[i] ^ y[i]);
    }
    return result;
} //funcionando para strings digitadas não pelo usuário

//-------------------------------------------------------------------------

 //número de 1's que match nas duas strings
size_t BinaryDistanceA(const string& x, const string& y){
    size_t result{0};
    size_t length = x.size();
    for(size_t i = 0; i < length; ++i){
        if((x[i] == 1) && (y[i] == 1))
            result++;
    }
    return result;
}

//número de 1's na string x que não match na string y
size_t BinaryDistanceB(const string& x, const string& y){
    size_t result{0};
    size_t length = x.size();
    for(size_t i = 0; i < length; ++i){
        if((x[i] == 1) && (y[i] == 0))
            result++;
    }
    return result;
}

//número de 0's na string x que não match na string y
size_t BinaryDistanceC(const string& x, const string& y){
    size_t result{0};
    size_t length = x.size();
    for(size_t i = 0; i < length; ++i){
        if((x[i] == 0) && (y[i] == 1))
            result++;
    }
    return result;
}

//número de 0's que match nas duas strings
size_t BinaryDistanceD(const string& x, const string& y){ 
    size_t result{0};
    size_t length = x.size();
    for(size_t i = 0; i < length; ++i){
        if((x[i] == 0) && (y[i] == 1))
            result++;
    }
    return result;
}

double RusselRao(const size_t a, const size_t b, const size_t c, const size_t d){
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

//----------------------------------------------------------------------------------------

//minimum number of strings transformations required to change s(x) in s(y)
//ideia retirada do site geekforgeeks
//verificar tipos
size_t editDistance(const string& x, const string& y){ //Possui versão recursiva e mais de uma interativa (versão escolhida aparenta ser a mais eficiente)
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

//--------------------------------------------------------------------------------------------------------

size_t valueDifferenceMetric(const string& x, const string& y, const string& alfabeto){
    size_t count{0};
    size_t length = x.size();
    for(size_t i = 0; i < length; ++i)
        count += (vdm(x[i], y[i], alfabeto) * weight(x[i], alfabeto)); //verificar se chamar a função assim funciona ou é melhor colocar em variáveis
    return count;
}

size_t vdm(const char xi, const char yi, const string& C){
    size_t count{0};
    size_t length = C.size();
    for(size_t c = 0; c < length; ++c)
        count += pow((P(length) - P(length)), 2); //sempre resulta 0, arrumar
    return count;
}


size_t weight(const char xi, const string& C, const size_t length){
    size_t somatorio{0};
    for (size_t i = 0; i < length; ++i)
        somatorio += pow(P(length), 2);

    return = sqrt(somatorio);
}

//probabilidade está certa?
double P(const size_t length){
    double p;
    p = (1 / length); //(?)
    return p;
}

//--------------------------------------------------------------

void diffMatching(const string& x, const string& y){
    size_t length = x.size();
    size_t count{0};
    for(size_t i = 0; i < length; ++i)
        count += abs(x[i] - y[i]);
    return count;
}   

void slopeMatching(const string& x, const string& y){
    size_t length = x.size();
    size_t count{0};
    for(size_t i = 0; i < length; ++i){
        size_t s1 = (x[i+1] - x[i]);
        size_t s2 = (y[i+1] - y[i]);
        count += abs(s1 - s2);
    }
    return count;
}

void physicalMatching();

//-----------------------------------------------------------------
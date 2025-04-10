#include <iostream>
#include <vector>
#include "NSA.hpp"

std::vector<string> generic(const std::vector<string> S, const size_t l, const int r){
    //gera um vetor de strings que todos falhem em match os elementos de S
    //Monitora novas samples de U (D pertence a U e S tbm pertence a U), se qualquer detector match as novas samples, classifica como nonself 
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//exhaustive
string ramdomString();

unsigned char match(const std::vector<string> S, const string d, const int r);

std::vector<string> exhaustive(const std::vector<string> S, const size_t l, const int r, const int T){
    std::vector<string> D;
    while (D.size() < T) {
        string d;
        d = ramdomString();//gera uma string alearória (binária?) pertencente a U
        if (!match(const std::vector<string> S, d r))
            D.push_back(d);
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//dynamic //ruim para strings longas e com valores grandes de r
unsigned int macthes(const string t, const std::vector<string> S){
    for (int i = 0; i < S.size(); ++i)
        if(t == S[i])
            return 1;
    
    return 0;
}

//representar o vetor de strings como um vetor de vetores de 0 e 1 ou blank?
std::vector<std::vector<size_t>> P1(const std::vector<string> S, const std::vector<string>t, std::vector<std::vector<size_t>> C,  const size_t l, const int r){ //backtracking
    for (size_t i = 1; i <= (l-r+1); ++i){
        while (1){ //enquanto o size de Ci[s] for menor que o size de t faça
            if (matches(t, S))
                //Ci[s] = 0
            else 
                //Ci[s] = Ci+1[ŝ + 0] + Ci+1[ŝ + 1]
            //muda t
        }
    }
}

void P2(std::vector<std::vector<size_t>> C){ //busca binaria? talvez aplicar uma árvore
    size_t T{0};
    for(int i = 0; i < C.size(); ++i)
        //Soma valores armazenados em C
    //determina um set de unmatched strings
    //first interval
        //P1 == Q1 ??
    //subsequent intervals
    for(int i = 2; i <= (l-r+1); ++i)
        //Calculo para Pi
        //Calculo para Qi
}

//chama P1 e P2
void dynamic(const std::vector<string> S, const size_t l, const int r);
//---------------------------------------------------------------------------------------------------------------------------------------------------
//Greedy
//P1 e P2 tbm
//---------------------------------------------------------------------------------------------------------------------------------------------------
//NSMutation Algorithm
//Introduces somatic hypermutation mechanism
//don't discart detectors that match self-data, but try to make them valid
//---------------------------------------------------------------------------------------------------------------------------------------------------
//Binary template
//utiliza tamplates 
//T thus contains (l - k + 1) . 2^k different elements
//Ts all the templates contained in at least one self-string (can be represented as a matrix that has 2^k rows), 
//one for each different w and (l-k+1) columns, one for each starting point i 
//Tn the set of remaining that are used to construct detectors(receptor) strings
//---------------------------------------------------------------------------------------------------------------------------------------------------
//DynamiCS
//deal with a nonself detection problem in a continuously changing environment
//primeiro gera detectores imaturos (random)
//Usando NS cria mais detectores imaturos até o número predefinido de criações
//Uma confirmação de segurança humana(coestimulação) é necessária para transformar um detector em um "Memory detector"
//---------------------------------------------------------------------------------------------------------------------------------------------------
//Schemata-based
//convert data space into schemata space (crompress the data)
//a schema r é definido como a conjunção dos intervalos como in the rules
//Um número de schemata comuns é evoluido primeiramente através de um algoritmo generico de coevolução in self-data space
//Esse número é "a number of non-inter-breeding subpopulations"
//Espécies são geradas aleatóriamente e outras são adicionadas até um número determinado
//Todas as espécies são decodificadas em comom schemata
//Detectors são gerados no espaço complementar da schemata usando a estratégia "gneration-and-test" 
//Se o detector contém algum comom schemata, ele é descartado
//--------------------------------------------------------------------------------------------------------------------------------------------------
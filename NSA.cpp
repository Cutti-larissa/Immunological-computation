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
//dynamic
std::vector<size_t> P1(const std::vector<string> S, std::vector<size_t> C,  const size_t l, const int r){
    for(int i = 1; i <= (l - r + 1); ++i){
        while(C.size() <= t){
            if()//ti,s matches with any bit string of S then
                C[i] = 0;
            else   
                C[i] = C[i+1] + C[i+1]; //arrumar
        }
    }
}
void P2();
void dynamic(const std::vector<string> S, const size_t l, const int r);
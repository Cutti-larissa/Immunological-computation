#include <iostream>

//mudar os tipos no final

struct elem{
    int dado;
    int x;
    int y;
    int z;
};

int volume(struct elem* elem){
    int vol;
    vol = x * y * z;
    return vol;
}

struct elem* interseccao(struct elem* e1, struct elem* e2){
    struct elem* ints;

    return ints;
}

int dist(struct elem* elem1, struct elem* elem2){
    int dis;
    struct elem* interc;
    interc = inteseccao(elem1, elem2);
    dis = (volume(elem1) - volume(interc)) / volume (elem2);
    return dis;
}

//fitness(struct elem* elem)

void nsdr(std::vector<std:vector<int>> S,int numLevels, std::vector<std:vector<int>> v){
    struct elem* c, p1, p2;
    int numGeracoes, popSize; // o que são essas infos?
    for(int i = 0; i < numLevels; ++i){
        //iniciar população com individuos aleatórios
    }
    for(int j = 0; j < numGeracoes; ++j){
        for(int k = 0; k < (popSize/2); ++k){
            //seleciona dois individuos (p1, p2) com probabilidade uniforme e sem substituição
            //aplica crossover para gerar um offstring (child)
            //Mutaciona a child
            if((dist(c, p1) < dist(c,p2)) && (fitness(c) > fitness(p1)))
                p1 = c;
            else if ((dist(c, p1) >= dist(c,p2)) && (fitness(c) > fitness(p2)))
                p2 = c;
        }
    }
    //extrair os melhores individuos da população e adicionar eles na solução final
}
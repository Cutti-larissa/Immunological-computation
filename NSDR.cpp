//detector rule "Ri"
//Ri: se a condiçãoi então NON_SELF para i = 1 até m
//condiçãoI = todos os X (de i até n) em [low, high] (de 1 até n)
//m = número de detection rules
//n = dimensão do espaço euclidiano 
//parte de condiçãoI de cada rule define um hypercubo em I^n
//um set de rules é evoluido e cada cromossomo codificou uma parte de condição de uma rule
//grau de anormalidade = grau de pertencimento de um NONSELF_SET
//parâmetro de variabilidade v = o nível de variabilidade de um NONSELF(point) para um SELF
//Embora v não seja considerado parte de um cromossomo, diferentes valores de v foram usados para gerar um negative detection rules hierarquico (agrupados em diferentes níveis)
//v = raios da hyperesfera em volta de cada amostra self 

//Uma nova amostra x é considerada satisfazendo a regra R se a hiperesfera com centro em x e raio v intercepta o hyperretangulo definido por uma detection rule R


//mudar os tipos no final

#include <iostream>

struct elem{
    int dado;
};

//seleciona um individuo com uma probabilidade uniforme e sem substituição
struct elem* select(std::vector<std:vector<int>> S){

}

//aplica crossover entre duas amostras para gerar um offspring (child)
struct elem* crossover(struct elem* p1, struct elem* p2){
    struct elem* child;
    return child;
}

int volume(struct elem* elem){
    int vol;
    //vol = multiplicação de todas as parcelas (highI - lowI), onde I vai de 1 a n
    return vol;
}

struct elem* interseccao(struct elem* e1, struct elem* e2){
    struct elem* ints;

    return ints;
}

int dist(struct elem* p, struct elem* c){
    int dis;
    struct elem* interc;
    interc = inteseccao(p, c);
    dis = (volume(p) - volume(p,c)) / volume (p);
    return dis;
}

int selsMatch(struct elem* elem){
    int contador{0};
    //acha o número de self-samples que match os subespaço definido pela regra elem
    return contador;
}

int fitness(struct elem* elem, int alpha){ //alpha = um coeficiente de sensibilidade que para uma regra específica determina o trade-off entre o volume coberto por ele e sua intercepção com o self-set
    int volume = volume(elem);
    int self = alpha * selsMatch(elem); 
    return volune - self; //total fitness é calculado como a soma do fitness de todos as evolved rules menos a sobreposição entre os hyperretangulos definido pelas rules 
}


//input = S (set de amostras self), número de níveis de desvio, vetor com o v de cada nível de desvio
//output = regras de detecção de alteração

void nsdr(std::vector<std:vector<int>> S,int numLevels, std::vector<std:vector<int>> v){
    struct elem* c, p1, p2;
    int numGeracoes, popSize; // o que são essas infos?
    for(int i = 0; i < numLevels; ++i){
        //D = iniciar população com individuos aleatórios
    }
    for(int j = 0; j < numGeracoes; ++j){
        for(int k = 0; k < (popSize/2); ++k){
            p1 = select(D);
            p2 = select(D);
            c = crossover(p1,p2);
            //Mutaciona a child
            if((dist(c, p1) < dist(c,p2)) && (fitness(c) > fitness(p1)))
                p1 = c;
            else if ((dist(c, p1) >= dist(c,p2)) && (fitness(c) > fitness(p2)))
                p2 = c;
        }
    }
    //extrair os melhores individuos da população e adicionar eles na solução final
}
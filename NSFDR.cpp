//dado um set de amostras de self, o algoritmo vai gerar regras de detecção difusas no espaço de nonself que pode determinar se uma nova amostra é normal ou anormal
//melhora a acurácia do método

//Rever expressões
//Usa hamming distance como medida de distância
//complexidade do alg O(num_gen x pop_size x |Self'|)

//Input: Self' (set de amostras self) e Fuzzy membership function
//Output: Um set de fuzzy rules como detectores negativos

struct amostra{

};

struct detectores{

};

//seleciona um individuo com uma probabilidade uniforme e sem substituição
struct detectores* select(){

}

//aplica crossover entre duas amostras para gerar um offspring (child)
struct detectores* crossover(struct detectores* p1, struct detectores* p2){
    struct detectores* child;
    return child;
}

int volume(struct detectores* e){
    int vol;
    vol = x * y * z;
    return vol;
}

struct detectores* interseccao(struct detectores* p1, struct detectores* p2){
    struct detectores* ints;

    return ints;
}

int dist(struct detectores* p1, struct detectores* p2){
    int dis;
    struct detectores* interc;
    interc = inteseccao(p1, p2);
    dis = (volume(p1) - volume(interc)) / volume (p2);
    return dis;
}

int fitness(struct detectores* elem){
    
}

void NSFDR(struct amostra* Self){
    struct detectores* p1, p2, c;
    //inicializar população como individuos aleatórios
    for (int j = 1; j < num_gen; ++j){
        for (int k = 1; k < (pop_size/2); ++k){
            p1 = select(Self); //Selecionar dos gerados aleatóriamente provavelmente
            p2 = select(Self);
            c = crossover(p1, p2);
            //mutaciona c (?)
            if ((dist(c,p1) < dist(c,p2)) & (fitness(c) > fitness(p1)))
                p1 = c;
            else if ((dist(c,p1) >= dist(c,p2)) & (fitness(c) > fitness(p2)))
                p2 = c;
        }
    }
    //Seleciona os melhores individuos da populaçao e adiciona eles ao set de detectores
}
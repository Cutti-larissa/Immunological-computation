#include <iostream>

struct arvore{
    //falta criar a árvore
    //implementar o knn algorithm 
    //implementar a mediana da distancia da arvore
    //implementar a travessia em ordem da árvore
    //entender o que é o dir
};

struct detector{
    int idade;
    double position;
};

struct elem{
    struct detector d;
    struct elem* prox;
};

struct lista{
    struct elem* inicio;
    struct elem* final;
};

//cria um detector de idade 0 e posição x
struct detector* criaDetector(){
    struct detector* d = (struct detector*) malloc(sizeof(struct detector));
    if (!d)
        return NULL;
    d->idade = 0;
    d->position = 0; //Onde iniciar?
    return d;
}

//insere o detector no final da lista
void insereDetector(struct lista* ld, const struct detector* d){
    if(!ld || !d)
        return;
    struct elem* e = (struct elem*) malloc(sizeof(struct elem));
    e->d = d;
    e->prox = NULL;
    if(!ld->final){
        ld->inicio = e;
        ld->final = e;
    }else{
        ld->final->prox = e;
        ld->final = e;
    }
}

//cria lista de detectores com um tamanho específico
struct lista* criarLista(int tamanho){
    int cont{0};
    struct lista* ld = (struct lista*) malloc(sizeof(struct lista));
    if(!ld)
        return NULL;
    ld->inicio = NULL;
    ld->final = NULL;
    while(cont < tamanho){
        struct detector* d = criaDetector();
        insereDetector(ld, d);
        cont++;
    }
    return ld;
}

void rns(const double r, double N, const int t, const int k, struct lista* ld){ //precisa passar o self set como parâmetro tbm
    int dir;
    while(parada != 0){ //enquanto o critério de parada não for atingido
        struct elem* aux = ld->inicio;
        for(struct elem* aux = ld->inicio; aux->prox != NULL; aux = aux->prox){ //para cada d no conjunto de detectors
            struct arvore* nearCells = ; //insere na árvore binária(já sai ordenado na passagem em ordem) a distância de cada k vizinhos de d no self set
            double nearestCells = ; //mediana da nearCells
            if(nearestCells < r){ //d está no self space
                dir = -1; //?
                if (aux->d->idade > t){
                    free(aux->d);
                    struct detector* d = criaDetector(); //precisa iniciar no mesmo lugar que o que foi excluido estava?
                    aux->d = d;
                }else{
                    aux->d->idade++;
                    aux->d->position = aux->d->position + N*dir; //tá certo isso?
                }
            }else{ //d não está no self space
                aux->d->idade = 0;
                dir = 1; //?
                aux->d->position = aux->d->position + N*dir;
            }
        } 
    }
}

int main(){
    int tamanho, t, k;
    double r, N;
    struct lista* ld = criaLista(tamanho);
    rns(r, N, t, k, ld); //retorna objetivo no ld?
}
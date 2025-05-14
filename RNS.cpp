#include <iostream>
#include <random>
#include <MinHeap.hpp> //precisa atualizar para utilizar aqui

struct detector{
    int idade;
    int pX; //caso aumente, trocar representação por um vetor n-dimensional
    int pY; //por enquanto, uma representação de inteiros, talvez mudar para floating point mais para frente
};

struct elem{
    struct detector* d;
    struct elem* prox;
};

struct lista{
    struct elem* inicio;
    struct elem* final;
};

//gera uma número aleatório dentro do range do hyperespaço
int randomG(const int min, const int max){ //Implementação adaptada do site geek for geeks
    int ran;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    ran = distrib(gen);
    return ran;
}

//cria um detector de idade 0 e posição x do hyperespaço
struct detector* criaDetector(){
    struct detector* d = (struct detector*) malloc(sizeof(struct detector));
    if (!d){perror("Erro ao alocar memória para o detector!\n"); return NULL;}
    d->idade = 0;
    int min = -2000; int max = 2000; //range do hyperespaço
    d->pX = randomG(min, max);//heapld, struct detector* d){
    if(!ld || !d)
        return;
    struct elem* e = (struct elem*) malloc(sizeof(struct elem));
    e->d = d;
    e->prox = NULL;
    if(!ld->final)
        ld->inicio = e;
    else
        ld->final->prox = e;
    ld->final = e;
}

//cria lista de detectores com um tamanho específico
struct lista* criarLista(int tamanho){
    int cont{0};
    struct lista* ld = (struct lista*) malloc(sizeof(struct lista));
    if(!ld){perror("Erro ao alocar memória para a lista!\n"); return NULL;}
    ld->inicio = NULL;
    ld->final = NULL;
    while(cont < tamanho){
        struct detector* d = criaDetector();
        insereDetector(ld, d);
        cont++;
    }
    return ld;
}

//calcula a distância entre o detector e a mediana dos seus K vizinhos mais próximos
int dist(struct detector* d, double nC){
    int dis{0};
    std:: cout << "Apenas testando se compila\n";
    return dis;
}

std::vector<std::vector<int>> achaKMenores(struct detector* d, std::vector<std::vector<int>> S){
    std::vector<std::vector<int>> selfs; //rever se esse seria o melhor tipo para armazenar selfs
    MinHeap<std::vector<int>> minHeap(S.size()); //tamanho da minHeap = size de self
    minHeap.buildHeap(S); //faz uma minheap com os selfs
    for(int j = 0; j < k; ++j){ //extrai da minHeap dos k menores
        std::vector<int> self = minHeap.extractMin();
        selfs.push_back(self);
    }
}

int mediana(std::vector<std::vector<int>> nC){
    int med{0};
    if ((nC.size() % 2) == 0)
        //med recebe a média da soma dos dois valores do meio de nC
    else
        //med recebe o valor do meio de nC
    return med;
}


//algoritmo do livro
void rns(const std::vector<std::vector<int>> S; const double r, double N, const int t, const int k, struct lista* ld){ 
    int dir{0}; //o que é o dir?
    int parada{1}; //qual é o critério de parada?
    while(parada != 0){ //enquanto o critério de parada não for atingido
        struct elem* aux = ld->inicio;
        for(struct elem* aux = ld->inicio; aux->prox != NULL; aux = aux->prox){ //para cada d no conjunto de detectors
            std::vector<std::vector<int>> nearCells = achaKMenores(aux->d, S); //KNN de d
            double nearestSelfs = mediana(nearCells); //mediana da nearCells
            if(dist(aux->d,nearestSelfs) < r){ //d está no self space
                dir = -1; //?
                if (aux->d->idade > t){
                    free(aux->d); //talvez tenha que remover da lista o antigo e adicionar o novo
                    struct detector* d = criaDetector(); 
                    aux->d = d; //substitui detector
                }else{
                    aux->d->idade++;
                    aux->d->pX = aux->d->pX + (N*dir); //tá certo isso?
                    aux->d->pY = aux->d->pY + (N*dir);
                }
            }else{ //d não está no self space, mesmo quando não está no self space se move?
                aux->d->idade = 0;
                dir = 1; //?
                aux->d->pX = aux->d->pX + (N*dir);
                aux->d->pY = aux->d->pY + (N*dir);
            }
        } 
        if (ld->final->d) //talvez algum teste que todos estejam fora do self space ou algum número específico seja atingido para não ficar rodando para sempre
            parada = 0;
    }
}

int main(){
    //hyperespaço aleatório de 2000 por 2000 inicialmente (algo 2D) com os selfs aqui dentro
    std::vector<std::vector<int>> S; //self samples (teste inicial)
    std::vector<int> a{0,0};
    S.push_back(a);
    std::vector<int> b{1990, -1990};
    S.push_back(b);
    std::vector<int> c{10, 576};
    S.push_back(c);
    std::vector<int> d{-200, -759};
    S.push_back(d);
    std::vector<int> e{848, -239};
    S.push_back(e);
    int tamanho{5};

    double r{10}; //raio de distância para match
    double N{3}; //valor eta, taxa de adaptação dos detectores
    int t{6}; //idade máxima do detector
    int k{3}; //parâmetro k do KNN
    struct lista* ls = criarLista(tamanho); //lista de detectores;
    rns(S, r, N, t, k, ls);
    return 0;
}
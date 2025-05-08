#include <iostream>
#include <vector>
#include <algorithm>    // std::shuffle (mutation)
#include <random>       // std::default_random_engine (mutation)
#include <chrono>       // std::chrono::system_clock (mutation)
#include "StringMatchingRule.hpp"

//S = conjunto de dados self
//l = tamanho dos dados
//r = parâmetro(limite) de matching, acredito que seja o número de detectores escolhidos
//retorno = um conjunto de detectores
std::vector<std::string> generic(const std::vector<string> S, const size_t l, const int r){ 
    //gera um conjunto de detectores que todos falhem em match os elementos de S
    //Monitora novas amostras de U, se qualquer detector match as novas amostras, classifica como nonself a amostra 
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//String representation
//Cada detector é representado como uma string de tamanho fixo de um alfabeto finito (ex.: binário [0, 1])
//--------------------------------------------------------------------------------------------------------------------------------------------------
//exhaustive -> Não muito eficiente, necesidade de poder computacional cresce com o tamanho de self para gerar os detectores aleatóriamente
//Para muitas escolhas de l e r e a composição de S, as gerações de detectores pode ser proibitiva
//Está funcionando, mas é preciso colocar um critério de parada para caso não existam detectores
//Arquivo de teste (t.cpp) na pasta extra

std::string randomDetector(const size_t l){
    static const char alfabeto[] =  "01"; //no caso de for binario, se não, tem que estudar a possibilidade de usar o S ou o alfabeto do espaço considerado
    std::string tmp_s;
    tmp_s.reserve(l);

    for (int i = 0; i < l; ++i) {
        tmp_s += alfabeto[rand() % (sizeof(alfabeto) - 1)];
    }
 
    return tmp_s;
}

unsigned char match(const std::vector<std::string> S, const std::string d, const size_t l, const int r){
    unsigned short matching{0};
    size_t size{S.size()};
    for (int i = 0; i < size; ++i){
        matching = rcb(S[i], d, l, r);
        if (matching == 1)
            return 1;
    }
    return 0;
}

//S = conjunto de self
//l = tamanho das strings(dados)
//r = parâmetro(limite) de matching (para a rcb matching rule), 1 <= r <= l
//T = tamanho de repertório (número de detectores)
//retorno = conjutno de detectores
//matching rule = rcb
std::vector<std::string> exhaustive(const std::vector<std::string> S, const size_t l, const unsigned int r, const int T){
    std::vector<std::string> D; //inicializa o conjunto vazio
    while (D.size() < T) {
        std::string d;
        d = randomDetector(l);//gera uma string de tamanho l alearória (binária?) de um alfabeto definido(binário?)
        if (!match(S, d, l, r))
            D.push_back(d);
    }
    return D;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
//dynamic -> ruim para strings longas e com valores grandes de r (programação dinâmica)
//utiliza rcb tbm
unsigned int macthes(const string t, const std::vector<string> S){
    for (int i = 0; i < S.size(); ++i)
        if(t == S[i])
            return 1;
    
    return 0;
}

//representar o vetor de strings como um vetor de vetores de 0 e 1 ou blank?
//programação dinamica, pesquisar!!
std::vector<std::vector<size_t>> P1(const std::vector<string> S, const std::vector<string>t, std::vector<std::vector<size_t>> C,  const size_t l, const int r){ //backtracking
    for (size_t i = 1; i <= (l-r+1); ++i){
        while (C[i][s] <= t){ //enquanto o size de Ci[s] for menor que o size de t faça
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
void dynamic(const std::vector<std::string> S, const size_t l, const int r);
//---------------------------------------------------------------------------------------------------------------------------------------------------
//Greedy (programação dinâmica)
//P1 e P2 tbm
//rever o que é template

//Dois arrays Ds e Dr são criados
//Ds é usado para "seguir" os templates, os detectors com entrada diferente de 0 são "templates de dectores válidos"
//Dr indica para cada template, o número de strings ainda unmached por detectores (anteriores?)
void P1(const std::vector<string> S, const std::vector<string>t, std::vector<std::vector<size_t>> C,  const size_t l, const int r); 
//Para gerar novos detectores, aqueles templates matching a maioria das unmacheds nonselfs strings são selecionados
//O array Dr é atualizado toda vez que um novo detector é gerado, ficando com Cr e C'r (ao invés de Dr) e incrementando eles 
void P2(std::vector<std::vector<size_t>> C)
void greedy(const std::vector<std::string> S, const size_t l, const int r); //chama P1 e P2

//---------------------------------------------------------------------------------------------------------------------------------------------------
//NSMutation Algorithm
//Introduz somatic hypermutation mechanism
//Não discarta os detectores que match self-data como no exhaustive, mas tenta os deixar válidos
//chama ramdomDetector e match iguais ao exhaustive
//demora mais que o exhaustive se quando match mudar toda a string
//Para match na região r:
//retorno de rcb deve ser i se deu match e 0 se não deu
//match na região r mesmo desempenho que exhaustive quando o exhaustive encontra
//talvez meu algoritmo esteja errado ou com um desempenho pior do que o esperado

char randomL(){
    static const char alfabeto[] =  "01";
    char letra = alfabeto[rand() % 2];
    return letra;
}
 
unsigned char match(const std::vector<std::string> S, std::string d, const size_t l, const int r){
    unsigned short matching{0};
    size_t size{S.size()};
    for (int i = 0; i < size; ++i){
        matching = rcb(S[i], d, l, r);
        if (matching != 0){
        for (int j = matching - r; j <= matching; ++j)
            d[j] = randomL();
            --i;
        }
    }
    return 0;
}

std::vector<std::string> mutation(const std::vector<std::string> S, const size_t l, const unsigned int r, const int T){
    std::vector<std::string> D;
    while (D.size() < T) {
        std::string d;
        d = randomDetector(l);
        if(!(match(S, d, l, r)))
            D.push_back(d);
    }
    return D;
}
   
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
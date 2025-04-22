//Baseado na "Monte Carlo integration" para gerar negative detectors
//Monte Carlo integration foi usado para estimar o volume do espaço self e nonself, isso foi usado para calcular a quantidade de detectores necessários para cobrir o espaço nonself 
//"Anelamento simulado" foi usado para otimizar a distribuição dos dectores no espaço nonself
#include "math.h"


float hyperCvolume(int raio, int n){
    float volume = ((2 * r) / sqrt(n));
    volume = pow(volume, n);
    return volume; 
}
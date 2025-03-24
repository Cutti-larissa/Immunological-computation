//Retorna o número de diferentes caracteres entre duas strings 
size_t HammingDistance(const string x, const string y, const size_t lenght);//funcionando para strings digitadas não pelo usuário

size_t BinaryDistanceA(const string x, const string y, const size_t lenght);
size_t BinaryDistanceB(const string x, const string y, const size_t lenght);
size_t BinaryDistanceC(const string x, const string y, const size_t lenght);
size_t BinaryDistanceD(const string x, const string y, const size_t lenght);

double RusselRao(const size_t a, const size_t b, const size_t c, const size_t d);
double JacardNeedham(const size_t a, const size_t b, const size_t c);
double Kulzinski(const size_t a, const size_t b, const size_t c);
double SokalMichener(const size_t a, const size_t b, const size_t c, const size_t d);
double RogersTanimoto(const size_t a, const size_t b, const size_t c, const size_t d);
double Yule(const size_t a, const size_t b, const size_t c, const size_t d);

size_t editDistance(); //recursivo 
//olhar implementação https://www.geeksforgeeks.org/edit-distance-dp-5/

void valueDifferenceMetric(const string x, const string y, const size_t lenght);
void vdm(const char xi, const char yi, const string C, const size_t lenght);
void weight(const char xi, const string C, const size_t lenght);
void P(const char ai, const string C, const size_t lenght);

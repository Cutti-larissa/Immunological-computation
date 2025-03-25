//Retorna o número de diferentes caracteres entre duas strings 
size_t HammingDistance(const string& x, const string& y);//funcionando para strings digitadas não pelo usuário

size_t BinaryDistanceA(const string& x, const string& y);
size_t BinaryDistanceB(const string& x, const string& y);
size_t BinaryDistanceC(const string& x, const string& y);
size_t BinaryDistanceD(const string& x, const string& y);

double RusselRao(const size_t a, const size_t b, const size_t c, const size_t d);
double JacardNeedham(const size_t a, const size_t b, const size_t c);
double Kulzinski(const size_t a, const size_t b, const size_t c);
double SokalMichener(const size_t a, const size_t b, const size_t c, const size_t d);
double RogersTanimoto(const size_t a, const size_t b, const size_t c, const size_t d);
double Yule(const size_t a, const size_t b, const size_t c, const size_t d);

size_t editDistance(const string& x, const string& y);

size_t valueDifferenceMetric(const string x, const string y, const size_t length);
size_t vdm(const char xi, const char yi, const string C, const size_t length);
size_t weight(const char xi, const string C, const size_t length);
double P(const char ai, const string C, const size_t length);

void diffMatching(const string& x, const string& y);
void slopeMatching(const string& x, const string& y);
void physicalMatching();

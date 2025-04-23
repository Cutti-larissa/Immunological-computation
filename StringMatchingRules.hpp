#ifndef STRING__MATCH_RULE
#define STRING__MATCH_RULE

//fractal like shape
size_t HammingDistance(const string& x, const string& y);
//---------------------------------------------------------------------------------------
size_t BDa(const string& x, const string& y);
size_t BDb(const string& x, const string& y);
size_t BDc(const string& x, const string& y);
size_t BDd(const string& x, const string& y);

double RusselRao(const size_t a, const size_t b, const size_t c, const size_t d);
double JacardNeedham(const size_t a, const size_t b, const size_t c);
double Kulzinski(const size_t a, const size_t b, const size_t c);
double SokalMichener(const size_t a, const size_t b, const size_t c, const size_t d);
double RogersTanimoto(const size_t a, const size_t b, const size_t c, const size_t d); //fractal like shape
double Yule(const size_t a, const size_t b, const size_t c, const size_t d);
//---------------------------------------------------------------------------------------
size_t editDistance(const string& x, const string& y);
//---------------------------------------------------------------------------------------
//Arrumar lógica
size_t valueDifferenceMetric(const string x, const string y, const size_t length);
size_t vdm(const char xi, const char yi, const string C, const size_t length);
size_t weight(const char xi, const string C, const size_t length);
double P(const char ai, const string C, const size_t length);
//---------------------------------------------------------------------------------------
void diffMatching(const string& x, const string& y, const size_t N);
void slopeMatching(const string& x, const string& y, const size_t N);
void physicalMatching(const string& x, const string& y, const size_t N, const int mi);
//---------------------------------------------------------------------------------------
short rcb(const string& x, const string& y, const size_t length, const size_t r);
//---------------------------------------------------------------------------------------
short rcmr(const string& x, const string& y, const size_t length, const size_t r);
//---------------------------------------------------------------------------------------
//real-value
size_t euclidianDistance(const std::vector<size_t> x, const std::vector<size_t> y, const size_t length);
size_t paticialED(const std::vector<size_t> x, const std::vector<size_t> y, const size_t length, const size_t w); //variation of the euclidian distance (specific window)
size_t minkowskiDistance(const std::vector<size_t> x, const std::vector<size_t> y, const size_t length, const size_t l); //lambda 1 = manhattan d / lambda 2 = euclidian d
void chebyshevDistance(); //infinity norm / maximum of the differences for all features
//---------------------------------------------------------------------------------------
//mixed
void HEOM(); //heterogeneous Euclidian-Overlap Metric
void heom();
void HVDM(); //heterogeneous Value Difference Metric
void hvdm();

#endif

#ifndef STRING__MATCH_RULE
#define STRING__MATCH_RULE

//fractal like shape
size_t HammingDistance(const string& x, const string& y);
//---------------------------------------------------------------------------------------
size_t BinaryDistanceA(const string& x, const string& y);
size_t BinaryDistanceB(const string& x, const string& y);
size_t BinaryDistanceC(const string& x, const string& y);
size_t BinaryDistanceD(const string& x, const string& y);
//---------------------------------------------------------------------------------------
double RusselRao(const size_t a, const size_t b, const size_t c, const size_t d);
double JacardNeedham(const size_t a, const size_t b, const size_t c);
double Kulzinski(const size_t a, const size_t b, const size_t c);
double SokalMichener(const size_t a, const size_t b, const size_t c, const size_t d);
double RogersTanimoto(const size_t a, const size_t b, const size_t c, const size_t d); //fractal like shape
double Yule(const size_t a, const size_t b, const size_t c, const size_t d);
//---------------------------------------------------------------------------------------
size_t editDistance(const string& x, const string& y);
//---------------------------------------------------------------------------------------
size_t valueDifferenceMetric(const string x, const string y, const size_t length);
size_t vdm(const char xi, const char yi, const string C, const size_t length);
size_t weight(const char xi, const string C, const size_t length);
double P(const char ai, const string C, const size_t length);
//---------------------------------------------------------------------------------------
void diffMatching(const string& x, const string& y);
void slopeMatching(const string& x, const string& y);
void physicalMatching();
//---------------------------------------------------------------------------------------
//gridlike shape
void rcbMatchingA(const string& x, const string& y, size_t r); 
void rcbMatchingB(const string& x, const string& y, size_t r); 
void rcbMatchingC(const string& x, const string& y, size_t r); 
void rcbMatchingD(const string& x, const string& y, size_t r); 
//---------------------------------------------------------------------------------------
//similar a gridlike shape but simpler
void rChunkMatching();
//---------------------------------------------------------------------------------------
//real-value
void euclidianDistance();
void paticialED(); //variation of the euclidian distance (specific window)
void minkowskiDistance(); //lambda 1 = manhattan d / lambda 2 = euclidian d
void chebyshevDistance(); //infinity norm / maximum of the differences for all features
//---------------------------------------------------------------------------------------
//mixed
void HEOM(); //heterogeneous Euclidian-Overlap Metric
void heom();
void HVDM(); //heterogeneous Value Difference Metric
void hvdm();

#endif

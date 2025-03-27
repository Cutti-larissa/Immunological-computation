#ifndef NSA__HPP
#define NSA__HPP
#include <iostream>
#include <string>
#include <vector>
/*generate ramdom candidates
if it maatches self-samples - discart and generate ramdom candidate again
else - accept as new detector
if there is enough detectors - finish
else - generate one more ramdom candidate*/

std::vector<string> generic(const std::vector<string> S, const size_t l, const int r);

std::vector<string> exhaustive(const std::vector<string> S, const size_t l, const int r, const int T); 
//4.3 - 4.5 detector generation using strings representation in NSA 
//4.6 -4.8 detector generation for real-valued and hybrid representation
//4.9 negative data bases and algorithms to generate it
#endif
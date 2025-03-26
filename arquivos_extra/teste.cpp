#include <iostream>
#include <string>

unsigned short x(const char i, const char j){
	if(i != j)
		return 1;
	return 0;
}

size_t HammingDistance(const std::string x, const std::string y, const size_t length){ 
    size_t result{0};
    for(size_t i = 1; i <= length; ++i){
        result += (x[i-1] ^ y[i-1]);//conferir lógica
    }
	return result;
}

int main(){
	int diferentes;
	size_t length{11}; 
	std::string x{"AATGCGGCCTT"};
	std::string y{"AAUGCGGCCUU"};
	diferentes = HammingDistance(x, y, length);
	std::cout << "Caracteres diferentes entre x e y = " << diferentes << std::endl;
	return 0;
}

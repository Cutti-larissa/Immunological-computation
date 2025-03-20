#include <iostream>
#include <string>
#include <typeinfo>

int main(){
	std::string x;
	std::cin >> x;
	std::cout << "Tipo = " << typeid(x[2]).name() << std::endl;
	return 0;
}

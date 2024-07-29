#include "whatever.hpp"
#include <string>

int main()
{
	int a = 2;
	int b = 3;
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min = " << min(a, b) << std::endl;
	std::cout << "max = " << max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min = " << min(c, d) << std::endl;
	std::cout << "max = " << max(c, d) << std::endl;
}
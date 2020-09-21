#include <iostream>
#include <cstdint>
#include <string>

int main()
{
	std::string f, s;
	std::cin >> f >> s;

	std::cout << ( ( f.back()%2==0 || s.back()%2==1 ) ? "yes" : "no" ) << std::endl;

	return 0;
}

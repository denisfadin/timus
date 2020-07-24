#include <iostream>
#include <cstdint>

int main()
{
	uint32_t n, a, b;
	std::cin >> n >> a >> b;

	std::cout << ((n*a*b)<<1) << std::endl;

	return 0;
}

#include <iostream>
#include <cstdint>

int main()
{
	uint32_t k;
	std::cin >> k;

	for( uint32_t i = 3; i <= k; ++i )
		if( k % i == 0 )
		{
			std::cout << i-1 << std::endl;
			break;
		}

	return 0;
}

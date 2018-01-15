#include <iostream>
#include <cstdint>

int main()
{
	uint16_t k, n;
	std::cin >> k >> n;

  uint16_t cars = 0;
	for( uint16_t i = 0; i < n; ++i )
  {
		uint16_t a;
		std::cin >> a;
		cars += a;
	}

  int16_t result = cars - k*n;
	std::cout << ( result > 0 ? result : 0 ) << std::endl;

	return 0;
}

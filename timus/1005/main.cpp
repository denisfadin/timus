#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <vector>

int main()
{
	int32_t n;
	std::cin >> n;

	std::vector< int32_t > buf;
	for( int32_t i = 0; i < n; ++i )
	{
		int32_t x;
		std::cin >> x;

		buf.emplace_back( x );
	}

	std::sort( std::begin( buf ), std::end( buf ), std::greater< int32_t >() );

	int32_t a = buf[0];
	int32_t b = 0;

	for( int32_t i = 1; i < n; ++i )
	{
		if( a - b > 0 )
			b += buf[i];
		else
		  a += buf[i];
	}

	std::cout << std::abs( a - b ) << std::endl;

}

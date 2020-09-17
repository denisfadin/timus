#include <iostream>
#include <cstdint>
#include <vector>
#include <limits>
#include <functional>

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

   int32_t result = std::numeric_limits< int32_t >::max();

   std::function< void( int32_t, int32_t, int32_t ) > f = [&]( int32_t i, int32_t s1, int32_t s2 )
   {
      if( i == buf.size() )
         result = std::min( result, std::abs( s1 - s2 ) );
      else
      {
         f( i+1, s1 + buf[i], s2 );
         f( i+1, s1, s2 + buf[i] );
      }
   };

   f( 0, 0, 0 );

	std::cout << result << std::endl;
}

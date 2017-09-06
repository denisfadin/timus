#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>

int main()
{
   int16_t n;
   std::cin >> n;

   std::vector< bool > s_vec( n, false );
   for( int16_t i = 0; i < n; ++i )
   {
      int16_t s;
      std::cin >> s;
      s_vec[i] = static_cast< bool >( s );
   }

   std::vector< int16_t > buf( n, 0 );

   int16_t count0 = 0, count1 = 0;
   for( int16_t i = 0; i < n; ++i )
   {
      if( !s_vec[ i ] )
         ++count0;
      buf[i] += count0;

      if( s_vec[ n-1-i ] )
         ++count1;
      buf[ n-1-i ] += count1;
   }

   std::cout << *std::max_element( std::begin( buf ), std::end( buf ) ) << std::endl;

   return 0;
}

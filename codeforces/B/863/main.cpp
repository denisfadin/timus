#include <iostream>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   int32_t n;
   std::cin >> n;

   std::vector< int32_t > buf( 2*n );
   for( int32_t i = 0; i < 2*n; ++i )
      std::cin >> buf[i];

   std::sort( std::begin( buf ), std::end( buf ), std::greater< int32_t >() );

   int32_t result = INT32_MAX;

   for( int32_t i = 0; i < 2*n-1; ++i )
      for( int32_t j = i+1; j < 2*n; ++j )
      {
         int32_t res = 0;

         int32_t k = 0;
         while( true )
         {
            if( k == i )
               ++k;
            if( k == j )
               ++k;

            if( k >= 2*n )
               break;

            int32_t k2 = k+1;
            if( k2 == i )
               ++k2;
            if( k2 == j )
               ++k2;

            res += ( buf[k] - buf[k2] );

            k = k2+1;
         }

         //std::cout << i << " " << j << " - " << res << std::endl;

         result = std::min( result, res );
      }

   std::cout << result << std::endl;

   return 0;
}

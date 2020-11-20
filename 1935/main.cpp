#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   std::vector< uint16_t > A( N, 0 );
   for( uint32_t i = 0; i < N; ++i )
      std::scanf( "%" SCNu16, &A[ i ] );

   std::sort( A.begin(), A.end(), std::greater< uint16_t >() );

   uint16_t result = 0;
   uint16_t left, right;
   left = right = A[ 0 ];

   for( uint32_t i = 1; i < N; ++i )
   {
      if( i % 2 )
      {
         result += right;
         right = A[ i ];
      }
      else
      {
         result += left;
         left = A[ i ];
      }
   }

   result += left;
   result += right;

   std::printf( "%" PRIu16 "\n", result );

   return 0;
}

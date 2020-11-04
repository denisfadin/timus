#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <limits>
#include <algorithm>

int main()
{
   uint32_t L1, L2, L3;
   std::scanf( "%" SCNu32 "%" SCNu32 "%" SCNu32, &L1, &L2, &L3 );

   uint32_t C1, C2, C3;
   std::scanf( "%" SCNu32 "%" SCNu32 "%" SCNu32, &C1, &C2, &C3 );

   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   uint32_t A, B;
   std::scanf( "%" SCNu32 "%" SCNu32, &A, &B );
   if( A > B )
      std::swap( A, B );

   std::vector< uint32_t > distances( N + 1, 0 );
   for( uint32_t i = 2; i <= N; ++i )
      std::scanf( "%" SCNu32, &distances[ i ] );

   std::vector< uint32_t > result( N + 1, std::numeric_limits< uint32_t >::max() );
   result[ A ] = 0;
   for( uint32_t i = A + 1; i <= B; ++i )
   {
      for( uint32_t j = i - 1; j >= A; --j )
      {
         auto d = distances[ i ] - distances[ j ];
         if( d > L3 )
            break;

         auto c = C3;
         if( d <= L1 )
            c = C1;
         else if( d <= L2 )
            c = C2;

         result[ i ] = std::min( result[ i ], c + result[ j ] );
      }
   }

   std::printf( "%" PRIu32 "\n", result[ B ] );
}

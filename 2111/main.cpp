#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   uint32_t N;
   scanf( "%" SCNu32, &N );

   std::vector< uint16_t > distances( N, 0 );
   uint64_t weight = 0;

   for( int32_t i = 0; i < N; ++i )
   {
      scanf( "%" SCNu16, &distances[ i ] );
      weight += distances[ i ];
   }

   std::sort( distances.begin(), distances.end() );

   uint64_t result = 0;
   for( uint32_t i = 0; i < N; ++i )
   {
      result += weight * distances[ i ];
      weight -= distances[ i ];
      result += weight * distances[ i ];
   }

   printf( "%" PRIu64 "\n", result );

   return 0;
}

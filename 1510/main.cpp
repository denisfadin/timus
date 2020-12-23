#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< uint32_t > data( N );
   for( uint32_t i = 0; i < N; ++i )
      std::scanf( "%" SCNu32, &data[ i ] );

   std::sort( data.begin(), data.end() );

   std::printf( "%" PRIu32 "\n", data[ N >> 1 ] );

   return 0;
}

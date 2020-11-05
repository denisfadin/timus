#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< uint32_t > result( N + 1, 0 );
   result[ 1 ] = 1;
   result[ 2 ] = 1;
   result[ 3 ] = 2;
   for( uint32_t i = 4; i <= N; ++i )
      result[ i ] = result[ i - 1 ] + result[ i - 3 ] + 1;

   std::printf( "%" PRIu32 "\n", result[ N ] );

   return 0;
}

#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< uint16_t > data( N + 1, 0 );
   for( uint_fast32_t i = 1; i <= N; ++i )
      std::scanf( "%" SCNu16, &data[ i ] );

   std::sort( data.begin(), data.end() );

   char str_buf[ 4 ];
   std::scanf( "%s", str_buf );

   uint_fast16_t K;
   std::scanf( "%" SCNuFAST16, &K );

   for( uint_fast16_t i = 0; i < K; ++i )
   {
      uint_fast32_t idx;
      std::scanf( "%" SCNuFAST32, &idx );

      std::printf( "%" PRIu16 "\n", data[ idx ] );
   }

   return 0;
}

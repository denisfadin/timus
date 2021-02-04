#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< int32_t > data( N + 1, 0 );
   for( uint32_t i = 1; i <= N; ++i )
   {
      std::scanf( "%" SCNd32, &data[ i ] );
      data[ i ] += data[ i - 1 ];
   }

   uint32_t Q;
   std::scanf( "%" SCNu32, &Q );

   for( uint32_t i = 0; i < Q; ++i )
   {
      uint32_t p1, p2;
      std::scanf( "%" SCNu32 "%" SCNu32, &p1, &p2 );
      std::printf( "%" PRId32 "\n", data[ p2 ] - data[ p1 - 1 ] );
   }

   return 0;
}

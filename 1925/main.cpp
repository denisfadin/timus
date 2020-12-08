#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint16_t N, K;
   std::scanf( "%" SCNu16 "%" SCNu16, &N, &K );

   uint16_t sum_b = K, sum_g = 0;
   for( uint32_t i = 0; i < N; ++i )
   {
      uint16_t b, g;
      std::scanf( "%" SCNu16 "%" SCNu16, &b, &g );
      sum_b += b;
      sum_g += g;
   }

   int16_t result = static_cast< int16_t >( sum_b ) - (N + 1) * 2 - sum_g;

   if( result < 0 )
      std::printf( "Big Bang!\n" );
   else
      std::printf( "%" PRId16 "\n", result );

   return 0;
}

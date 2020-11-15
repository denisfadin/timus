#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint32_t N, K;
   std::scanf( "%" SCNu32 "%" SCNu32, &N, &K );

   uint32_t result1 = 0, result2 = 0;
   for( uint32_t i = 0; i < N; ++i )
   {
      uint32_t b;
      std::scanf( "%" SCNu32, &b );

      if( K > b )
         result2 += K - b;
      else
         result1 += b - K;
   }

   std::printf( "%" PRIu32 " %" PRIu32 "\n", result1, result2 );

   return 0;
}

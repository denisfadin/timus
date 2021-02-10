#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint32_t b;
   std::scanf( "%" SCNu32, &b );

   uint32_t c, d;
   std:scanf( "%" SCNu32 "%" SCNu32, &c, &d );

   uint32_t k, p;
   std::scanf( "%" SCNu32 "%" SCNu32, &k, &p );

   uint64_t sum = 0;
   for( uint32_t i = 1; i <= k; ++i )
      sum += c + i * d;

   uint64_t sum1 = ( sum + b ) * 100;
   uint64_t sum2 = sum * ( 100 + p );

   if( sum1 < sum2 )
   {
      std::printf( "Cash\n" );
      std::printf( "%" PRIu64 ".%.2" PRIu64 "\n", (sum2 - sum1) / 100, (sum2 - sum1) % 100 );
   }
   else
   {
      std::printf( "Insurance\n" );
      std::printf( "%" PRIu64 ".%.2" PRIu64 "\n", (sum1 - sum2) / 100, (sum1 - sum2) % 100 );
   }

   return 0;
}

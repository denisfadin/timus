#include <cstdint>
#include <cstdio>
#include <cinttypes>

uint32_t Do( uint32_t n, uint32_t k )
{
   uint32_t const team_fighters = n / k;
   uint32_t result = 0;
   for( uint32_t i = 1; i < k; ++i )
      result += team_fighters * ( k - i ) * team_fighters;

   uint32_t const tf = n % k;
   for( uint32_t i = 0; i < tf; ++i )
      result += team_fighters * ( k - 1 ) + ( tf - i - 1 );

   return result;
}

int main()
{
   uint16_t T;
   std::scanf( "%" SCNu16, &T );

   for( uint16_t t = 0; t < T; ++t )
   {
      uint32_t n, k;
      std::scanf( "%" SCNu32 "%" SCNu32, &n, &k );
      std::printf( "%" PRIu32 "\n", Do( n, k ) );
   }
   return 0;
}

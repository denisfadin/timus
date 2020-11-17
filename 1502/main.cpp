#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   uint32_t sum = ( N * (N+1) ) >> 1;

   uint64_t result = 0;
   for( uint32_t i = 0; i <= N; ++i )
   {
      result += sum;
      sum -= i;
      result += (N+1-i)*i;
   }

   std::printf( "%" PRIu64 "\n", result );

   return 0;
}

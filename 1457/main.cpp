#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   double result = 0;
   for( uint16_t i = 0; i < N; ++i )
   {
      uint32_t p;
      std::scanf( "%" SCNu32, &p );
      result += p;
   }

   result /= N;

   std::printf( "%.6lf\n", result );

   return 0;
}

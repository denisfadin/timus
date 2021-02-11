#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint32_t m, min;
   std::scanf( "%" SCNu32 "%" SCNu32, &m, &min );

   uint32_t c;
   std::scanf( "%" SCNu32, &c );

   uint32_t result = 0;
   double md = m;
   while( true )
   {
      if( md <= min )
         break;
      ++result;
      md *= 100-c;
      md /= 100;
   }

   std::printf( "%" PRIu32 "\n", result );

   return 0;
}

#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <algorithm>

int main()
{
   uint32_t a, b, c, d;
   std::scanf( "%" SCNu32 "%" SCNu32 "%" SCNu32 "%" SCNu32, &a, &b, &c, &d );

   uint32_t result;
   if( a >= c )
      result = a;
   else
   {
      result = a + ( ( c - a ) / ( b + d ) ) * b;
      auto r = ( c - a ) % ( b + d );
      result += std::min( b, r );
   }

   std::printf( "%" PRIu32 "\n", result );

   return 0;
}

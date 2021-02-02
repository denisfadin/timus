#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   // a = (2*N-p*(p-1))/(2*p)
   // p < [1+sqrt(1+8N)]/2 => 44720

   auto N2 = N << 1;
   for( uint32_t p = 44720; p > 0; --p )
   {
      auto x = p*(p-1);
      if( N2 <= x )
         continue;
      x = N2-x;
      if( x%(p<<1) )
         continue;

      std::printf( "%" PRIu32 " %" PRIu32 "\n", x/(p<<1), p );
      break;
   }

   return 0;
}

#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <utility>
#include <array>

int main()
{
   uint32_t p1, p2;
   std::scanf( "%" SCNu32 "%" SCNu32, &p1, &p2 );

   if( p1 > p2 )
      std::swap( p1, p2 );

   std::array< uint32_t, 31 > pow2sum;
   pow2sum[ 0 ] = 0;
   for( uint32_t i = 1; i < 31; ++i )
      pow2sum[ i ] = ( pow2sum[ i - 1 ] << 1 ) + ( i - 1 );

   auto calc = [ & ]( uint32_t p )
   {
      uint32_t result = 0;
      for( uint32_t i = 30; i > 0; --i )
      {
         uint32_t pow2 = 1 << i;
         if( p & pow2 )
         {
            result += pow2sum[ i ];
            p &= ~pow2;
            if( p )
               result += i - 1;
            else
               break;
         }
      }
      return result;
   };

   std::printf( "%" PRIu32 "\n", calc( p2 ) - calc( p1 ) );

   return 0;
}

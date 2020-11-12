#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <string>
#include <limits>
#include <array>

class Calculator
{
public:

   Calculator()
      : mCache( 901 * 8101, std::numeric_limits< uint16_t >::max() )
   {}

   void Calc( std::array< char, 101 >& result, uint32_t s1, uint32_t s2 )
   {
      if( s1 > 900 || s2 > 8100 )
      {
         result[ 0 ] = 0;
         return;
      }

      uint16_t size = Get( s1, s2 );
      if( size == 0 )
      {
         result[ 0 ] = 0;
         return;
      }
      size = ( size & 0xFF00 ) >> 8;

      uint32_t i = 0;
      while( s1 && s2 )
      {
         uint16_t r = Get( s1, s2 );
         r &= 0x00FF;
         result[ i++ ] = '0' + r;
         s1 -= r;
         s2 -= r * r;
      }
      result[ size ] = 0;
   }

private:

   std::vector< uint16_t > mCache;

   uint16_t Get( uint32_t s1, uint32_t s2 )
   {
      uint16_t& result = mCache[ s1 * 8101 + s2 ];
      if( result != std::numeric_limits< uint16_t >::max() )
         return result;

      result = 0;
      if( s1 >= 1 && s1 <= 9 && s2 == s1 * s1 )
         result = ( 1 << 8 ) + static_cast< uint8_t >( s1 );
      else
      {
         for( uint8_t i = 1; i <= 9; ++i )
         {
            if( s1 <= i || s2 <= i*i )
               continue;

            uint16_t r = Get( s1 - i, s2 - i*i );
            if( r == 0 )
               continue;
            r = ( r & 0xFF00 ) >> 8;
            if( r == 100 )
               continue;

            uint16_t res = ( ( r + 1 ) << 8 ) + i;
            if( result == 0 || result > res )
               result = res;
         }
      }
      return result;
   }
};

int main()
{
   Calculator calc;

   uint32_t T;
   std::scanf( "%" SCNu32, &T );

   std::array< char, 101 > buf;
   for( uint32_t i = 0; i < T; ++i )
   {
      uint32_t s1, s2;
      std::scanf( "%" SCNu32 "%" SCNu32, &s1, &s2 );

      calc.Calc( buf, s1, s2 );
      if( buf[ 0 ] == 0 )
         std::printf( "No solution\n" );
      else
         std::printf( "%s\n", buf.data() );
   }

   return 0;
}

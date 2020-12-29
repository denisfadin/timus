#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <array>

int main()
{
   std::array< char, 251 > N;
   N.fill( 0 );

   std::scanf( "%s", N.data() );
   uint32_t sum = 0;
   for( uint16_t i = 0; N[ i ] != 0; ++i )
      sum += N[ i ] - '0';

   uint32_t rem = sum % 3;
   if( rem == 0 )
      std::printf( "2\n" );
   else
      std::printf( "1\n%" PRIu32 "\n", rem );

   return 0;
}

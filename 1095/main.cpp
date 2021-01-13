#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <array>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   constexpr std::array< uint32_t, 7 > const variants = {
      3241,
      1324,
      1234,
      2341,
      1243,
      1342,
      2134
   };

   std::array< char, 21 > buffer;
   std::array< uint32_t, 10 > digit_count;

   for( uint32_t n = 0; n < N; ++n )
   {
      buffer.fill( 0 );
      std::scanf( "%s", buffer.data() );

      digit_count.fill( 0 );
      for( auto sym : buffer )
      {
         if( sym == 0 )
            break;
         ++digit_count[ sym - '0' ];
      }

      for( uint32_t i = 1; i < 5; ++i )
         --digit_count[ i ];

      uint64_t rem = 0;
      for( uint32_t i = 1; i <= 9; ++i )
      {
         while( digit_count[ i ] )
         {
            std::putchar( '0' + i );

            rem = ( rem * 10 + i ) % 7;

            --digit_count[ i ];
         }
      }

      rem = ( rem * 10000 ) % 7;
      rem = ( 7 - rem ) % 7;

      std::printf( "%" PRIu32, variants[ rem ] );

      while( digit_count[ 0 ] )
      {
         std::putchar( '0' );
         --digit_count[ 0 ];
      }

      std::putchar( '\n' );
   }

   return 0;
}

#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <array>

void Do( uint32_t pos, uint32_t size, std::array< char, 20000 > const& buf )
{
   uint32_t left_size = ( size - 1 ) >> 1;
   if( left_size )
      Do( pos + 1, left_size, buf );

   std::putchar( buf[ pos ] );

   uint32_t right_size = left_size + ( size - 1 ) % 2;
   if( right_size )
      Do( pos + left_size + 1, right_size, buf );
}

int main()
{
   std::array< char, 20000 > buf;
   uint32_t size = 0;

   while( true )
   {
      char sym = std::getchar();
      if( sym == EOF )
         break;
      else if( sym == '\n' )
         continue;
      buf[ size ] = sym;
      ++size;
   }

   Do( 0, size, buf );

   std::printf( "\n" );

   return 0;
}

#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <array>

int main()
{
   std::array< char, 101 > str;
   std::scanf( "%s", str.data() );

   int16_t add = 5;
   for( char& sym : str )
   {
      if( sym == 0 )
         break;
      int16_t x = static_cast< int16_t >( sym ) - add - 'a';
      while( x < 0 )
         x += 26;
      sym = x + 'a';
      add += x;
   }

   std::printf( "%s\n", str.data() );

   return 0;
}

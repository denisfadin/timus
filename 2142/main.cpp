#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <algorithm>

int main()
{
   uint32_t a, b, c;
   std::scanf( "%" SCNu32 "%" SCNu32 "%" SCNu32, &a, &b, &c );

   uint32_t x, y, z;
   std::scanf( "%" SCNu32 "%" SCNu32 "%" SCNu32, &x, &y, &z );

   auto check = [ & ]()
   {
      {
         auto min = std::min( a, x );
         x -= min; a -= min;
         z -= std::min( a, z );
      }

      {
         auto min = std::min( b, y );
         y -= min; b -= min;
         z -= std::min( b, z );
      }

      if( x > c )
         return false;
      c -= x;

      if( y > c )
         return false;
      c -= y;

      if( z > c )
         return false;

      return true;
   };

   if( check() )
      std::printf( "It is a kind of magic\n" );
   else
      std::printf( "There are no miracles in life\n" );

   return 0;
}

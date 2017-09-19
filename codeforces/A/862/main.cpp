#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>

int32_t const MAX = 101;

int main()
{
   int16_t n;
   std::cin >> n;

   int16_t x;
   std::cin >> x;

   std::vector< bool > buf( MAX, false );
   for( int16_t i = 0; i < n; ++i )
   {
      int16_t num;
      std::cin >> num;
      buf[ num ] = true;
   }

   auto min = std::find( std::begin( buf ), std::end( buf ), false );
   int16_t pos = std::distance( std::begin( buf ), min );

   int16_t result = 0;
   if( x != pos )
   {
      if( x < pos )
         result = 1;
      else if( x > pos )
      {
         for( int16_t i = pos; i < x; ++i )
            if( !buf[i] )
               ++result;
         if( buf[ x ] )
            ++result;
      }
   }

   std::cout << result << std::endl;

   return 0;
}

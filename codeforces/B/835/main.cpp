#include <iostream>
#include <stdint.h>
#include <vector>

int main()
{
   int32_t k;
   std::cin >> k;

   std::vector< int32_t > buf( 10, 0 );
   int32_t sum = 0;

   while( sum < k )
   {
      char c = '9';
      std::cin >> c;

      if( std::cin.eof() )
         break;

      int16_t d = ( c-'0' );
      sum += ( d );
      buf[ 9 - d ] += 1;
   }

   if( sum >= k )
      std::cout << 0;
   else
   {
      int32_t result = 0;
      int32_t diff = k - sum;

      for( int16_t i = 9; i > 0 && diff > 0; --i )
      {
         int32_t cnt = buf[i];
         int32_t min = std::min( diff, cnt*i );
         result += ( min/i + ( min%i ? 1 : 0 ) );
         diff -= min;
      }

      std::cout << result;
   }

   std::cout << std::endl;

   return 0;
}

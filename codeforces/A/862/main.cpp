#include <iostream>
#include <stdint.h>

int main()
{
   int16_t n, x;
   std::cin >> n >> x;

   int16_t cnt_less = 0;
   bool x_exist = false;

   for( int16_t i = 0; i < n; ++i )
   {
      int32_t num;
      std::cin >> num;

      if( num < x )
         ++cnt_less;
      else if( num == x )
         x_exist = true;
   }

   std::cout << ( x - cnt_less + ( x_exist ? 1 : 0 ) ) << std::endl;

   return 0;
}

#include <iostream>
#include <cstdint>

int main()
{
   uint16_t n;
   std::cin >> n;
   while( n > 0 )
   {
      --n;
      char d, a; // down, across
      std::cin >> d >> a;

      uint16_t result = 8;
      if( d <= 'b' || a == '1' )
         result--;
      if( d <= 'b' || a == '8' )
         result--;
      if( d >= 'g' || a == '1' )
         result--;
      if( d >= 'g' || a == '8' )
         result--;

      if( a <= '2' || d == 'a' )
         result--;
      if( a <= '2' || d == 'h' )
         result--;
      if( a >= '7' || d == 'a' )
         result--;
      if( a >= '7' || d == 'h' )
         result--;

      std::cout << result << std::endl;
   }

   return 0;
}

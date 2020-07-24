#include <iostream>

int main()
{
   int a, b;
   std::cin >> a >> b;
   a = 6 - std::max( a, b ) + 1;
   b = 6;
   if( a % 2 == 0 )
   {
      a /= 2;
      b /= 2;
   }
   if( a % 3 == 0 )
   {
      a /= 3;
      b /= 3;
   }
   std::cout << a << '/' << b << std::endl;

   return 0;
}

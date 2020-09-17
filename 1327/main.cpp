#include <iostream>
#include <cstdint>

int main()
{
   uint16_t a, b;
   std::cin >> a >> b;

   if( a%2 == 0 )
     ++a;

   auto d = b-a+1;

   std::cout << d/2 + d%2 << std::endl;

   return 0;
}

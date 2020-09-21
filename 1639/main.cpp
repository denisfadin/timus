#include <iostream>
#include <cstdint>

int main()
{
   uint16_t m, n;
   std::cin >> m >> n;

   std::cout << ( (m*n)%2 == 0 ? "[:=[first]" : "[second]=:]" ) << std::endl;
   
   return 0;
}

#include <iostream>
#include <cstdint>

int main()
{
   uint16_t n;
   std::cin >> n;

   for( uint32_t i = 1; i <= n; ++i )
      std::cout << i << " ";

   return 0;
}

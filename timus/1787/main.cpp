#include <iostream>
#include <cstdint>

int main()
{
   uint16_t k, n;
   std::cin >> k >> n;

   uint16_t result = 0;
   for( uint16_t i = 0; i < n; ++i )
   {
      uint16_t a;
      std::cin >> a;
      result += a;
      result -= std::min( result, k );
   }

   std::cout << result << std::endl;

   return 0;
}

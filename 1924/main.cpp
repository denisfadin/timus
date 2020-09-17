#include <iostream>
#include <cstdint>

int main()
{
   uint32_t n;

   std::cin >> n;

   uint32_t sum = ((1 + n) * n) >> 1;

   std::cout << (sum % 2 ? "grimy" : "black") << std::endl;

   return 0;
}

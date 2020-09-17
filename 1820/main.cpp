#include <iostream>
#include <cstdint>

int main()
{
   uint16_t n, k;
   std::cin >> n >> k;

   if( n <= k )
      std::cout << 2 << std::endl;
   else
      std::cout << (n<<1)/k + ( (n<<1)%k ? 1 : 0 ) << std::endl;

   return 0;
}

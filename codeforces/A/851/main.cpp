#include <iostream>
#include <stdint.h>

int main()
{
   int32_t n, k, t;
   std::cin >> n >> k >> t;
   if( t < k )
      std::cout << t;
   else if( t > n )
      std::cout << k-(t-n);
   else
      std::cout << k;

   std::cout << std::endl;

   return 0;
}

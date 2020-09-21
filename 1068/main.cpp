#include <cstdint>
#include <iostream>

int main()
{
   int32_t N;
   std::cin >> N;

   int32_t sz = ( N>1 ? N-1 : 1-N ) + 1;
   std::cout << ( 1+N ) * sz / 2 << std::endl;
}

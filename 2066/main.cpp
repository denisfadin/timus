#include <iostream>
#include <cstdint>

int main()
{
   int16_t a, b, c;
   std::cin >> a >> b >> c;

   std::cout << ((b==0 || b==1 || c==1) ? (a-b-c) : (a-b*c)) << std::endl;

   return 0;
}

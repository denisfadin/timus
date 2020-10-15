#include <cstdint>
#include <iostream>

int main()
{
   float P, Q;
   std::cin >> P >> Q;

   uint64_t P1 = P*100, Q1 = Q*100;

   for( uint64_t i = 2; ; ++i )
   {
      uint64_t min = P1 * i;
      uint64_t max = Q1 * i;

      uint64_t r = 10000 * ( min / 10000 + 1 );
      if( r < max )
      {
         std::cout << i << std::endl;
         break;
      }
   }

   return 0;
}

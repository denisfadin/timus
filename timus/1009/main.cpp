#include <iostream>
#include <cstdint>
#include <cmath>

int main()
{
   uint16_t n, k;
   std::cin >> n >> k;

   uint32_t result = (k-1)*std::pow( k, n-1 );
   if( n > 2 )
   {
      for( int16_t i = 2; i < n-1; ++i )
         result -= std::pow( k-1, n-i+1 )*(n-i);
      result -= (k-1);
   }     

   std::cout << result << std::endl;

   return 0;
}

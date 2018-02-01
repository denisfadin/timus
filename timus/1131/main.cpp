#include <iostream>
#include <cstdint>

int main()
{
   uint32_t n, k;
   std::cin >> n >> k;

   uint32_t result = 0;
   --n;
   for( uint32_t i = 1; i < k; i<<=1 )
   {
      if( n == 0 )
         break;

      ++result;
      n -= std::min( i, n );
   }

   result += n / k;

   if( n % k )
      ++result;

   std::cout << result << std::endl;

   return 0;
}

#include <iostream>
#include <cstdint>
#include <vector>

int main()
{
   uint16_t n;
   std::cin >> n;

   std::vector< uint16_t > buf( n*n, 0 );

   uint16_t idx = 0;
   for( uint16_t i = 0; i < n; ++i )
   {
      uint16_t k = n-1-i;
      buf[k] = ++idx;
      for( uint16_t j = 0; j < i; ++j )
      {
         k += n+1;
         buf[k] = ++idx;
      }
   }

   for( uint16_t i = 1; i < n; ++i )
   {
      uint16_t k = i*n;
      buf[k] = ++idx;
      for( uint16_t j = 0; j < n-i-1; ++j )
      {
         k += n+1;
         buf[k] = ++idx;
      }
   }

   for( uint16_t i = 0; i < n; ++i )
   {
      for( uint16_t j = 0; j < n; ++j )
         std::cout << buf[i*n+j] << " ";
      std::cout << std::endl;
   }

   return 0;
}

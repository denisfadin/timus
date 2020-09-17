#include <iostream>
#include <cstdint>

uint32_t calc( uint32_t i, uint32_t n, uint32_t m )
{
   if( n == 0 )
      return 1 % m;

   uint32_t result = 1;
   while( n > 0 )
   {
      result = ( result * i ) % m;
      --n;
   }

   return result;
}

int main()
{
   uint32_t n, m, y;
   std::cin >> n >> m >> y;

   bool exist = false;
   for( uint32_t i = 0; i < m; ++i )
      if( calc( i, n, m ) == y )
      {
         if( exist )
            std::cout << " ";
         std::cout << i;
         exist = true;
      }

   if( !exist )
      std::cout << -1;

   std::cout << std::endl;

   return 0;
}

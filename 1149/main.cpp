#include <iostream>
#include <cstdint>

void An( uint16_t n, uint16_t i = 1 )
{
   if( i > 1 )
      std::cout << ( i%2 ? "+" : "-" );
   std::cout << "sin(" << i;
   if( i < n )
      An( n, i+1 );
   std::cout << ")";
}

int main()
{
   uint16_t n;
   std::cin >> n;

   for( uint16_t i = 0; i < n-1; ++i )
      std::cout << "(";

   for( uint16_t i = 0; i < n; ++i )
   {
      An(i+1);
      std::cout << "+" << n-i;
      if( i < n-1 )
         std::cout << ")";
   }

   std::cout << std::endl;

   return 0;
}

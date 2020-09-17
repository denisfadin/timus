#include <iostream>
#include <cstdint>

const char* translate( uint16_t n )
{
   if( n <= 4 )
      return "few";
   else if( 5 <= n && n <= 9 )
      return "several";
   else if( 10 <= n && n <= 19 )
      return "pack";
   else if( 20 <= n && n <= 49 )
      return "lots";
   else if( 50 <= n && n <= 99 )
      return "horde";
   else if( 100 <= n && n <= 249 )
      return "throng";
   else if( 250 <= n && n <= 499 )
      return "swarm";
   else if( 500 <= n && n <= 999 )
      return "zounds";
   else if( n >= 1000 )
      return "legion";

   return "undefined";
}

int main()
{
   uint16_t n;
   std::cin >> n;

   std::cout << translate( n ) << std::endl;

   return 0;
}

#include <iostream>
#include <cstdint>
#include <vector>

int main()
{
   uint16_t n;
   std::cin >> n;

   std::vector< bool > buf;
   buf.resize( n+1, false );

   for( uint16_t i = 1; i < n+1; ++i )
   {
      buf[i] = true;

      while( true )
      {
         uint16_t k;
         std::cin >> k;

         if( k == 0 )
            break;

         if( buf[k] )
            buf[i] = false;
      }
   }

   uint16_t result = 0;
   for( uint16_t i = 1; i < n+1; ++i )
      if( buf[i] )
         ++result;

   std::cout << result << std::endl;
   for( uint16_t i = 1; i < n+1; ++i )
      if( buf[i] )
         std::cout << i << " ";

   return 0;
}

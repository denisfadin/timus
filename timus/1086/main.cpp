#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>

int main()
{
   uint32_t k;
   std::cin >> k;

   std::vector< uint32_t > buf;
   buf.push_back( 2 );

   for( uint32_t i = 0; i < k; ++i )
   {
      uint32_t n;
      std::cin >> n;

      uint32_t max = buf.back();
      while( n > buf.size() )
      {
         ++max;
         uint32_t sqrt_max = std::sqrt( max )+1;

         bool append = true;
         for( auto it = std::begin( buf ); it != std::end( buf ); ++it )
         {
            if( max % *it == 0 )
            {
               append = false;
               break;
            }
            if( *it > sqrt_max )
               break;
         }

         if( append )
            buf.push_back( max );
      }

      std::cout << buf[n-1] << std::endl;
   }
}

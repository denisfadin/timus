#include <iostream>
#include <stdint.h>
#include <vector>

int main()
{
   int16_t n, a, b;
   std::cin >> n >> a >> b;

   std::vector< std::pair< int16_t, int16_t > > stamps;
   for( int16_t i = 0; i < n; ++i )
   {
      int16_t x, y;
      std::cin >> x >> y;
      stamps.emplace_back( std::make_pair( x, y ) );
   }

   int32_t result = 0;

   for( int16_t i = 0; i < n; ++i )
      for( int16_t j = i+1; j < n; ++j )
      {
         auto const& x = stamps[i];
         auto const& y = stamps[j];

         if( ( ( x.first + y.first ) <= a && std::max( x.second, y.second ) <= b ) ||
             ( std::max( x.first, y.first ) <= a && ( x.second + y.second ) <= b ) ||
             ( ( x.second + y.second ) <= a && std::max( x.first, y.first ) <= b ) ||
             ( std::max( x.second, y.second ) <= a && ( x.first + y.first ) <= b ) ||
             ( ( x.first + y.second ) <= a && std::max( x.second, y.first ) <= b ) ||
             ( std::max( x.first, y.second ) <= a && ( x.second + y.first ) <= b ) ||
             ( ( x.second + y.first ) <= a && std::max( x.first, y.second ) <= b ) ||
             ( std::max( x.second, y.first ) <= a && ( x.first + y.second ) <= b ) )
         {
            result = std::max( result, x.first * x.second + y.first * y.second );
         }
      }

   std::cout << result << std::endl;
}

#include <iostream>
#include <cstdint>
#include <unordered_map>

int main()
{
   std::unordered_map< int32_t, int16_t > map;
   for( uint16_t i = 0; i < 3; ++i )
   {
      uint16_t n;
      std::cin >> n;

      while( n-- )
      {
         uint32_t a;
         std::cin >> a;

         auto it = map.find( a );
         if( it == std::end( map ) )
            map.insert( std::make_pair< int32_t, int16_t >( a, 1 ) );
         else
            ++(it->second);
      }
   }

   uint16_t result = 0;
   for( auto const& p : map )
      if( p.second == 3 )
         ++result;

   std::cout << result << std::endl;

   return 0;
}

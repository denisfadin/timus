#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <array>
#include <string_view>
#include <algorithm>

int main()
{
   std::ios_base::sync_with_stdio( false );

   constexpr std::array< std::string_view, 4 > const houses = {
      "Slytherin",
      "Hufflepuff",
      "Gryffindor",
      "Ravenclaw"
   };

   auto house_pos = [ &houses ]( std::string_view h )
   {
      return std::distance( houses.begin(),
                            std::find( houses.begin(), houses.end(), h ) );
   };

   std::vector< std::vector< std::string > > data( houses.size() );

   uint16_t N;
   std::cin >> N >> std::ws;
   for( uint16_t i = 0; i < N; ++i )
   {
      std::string name, house;
      std::getline( std::cin, name );
      std::getline( std::cin, house );

      data[ house_pos( std::string_view{ house } ) ].push_back( std::move( name ) );
   }
   for( uint16_t house_pos = 0; house_pos < houses.size(); ++house_pos )
   {
      std::cout << houses[ house_pos ] << ":" << std::endl;
      for( auto const& name : data[ house_pos ] )
         std::cout << name << std::endl;
      std::cout << std::endl;
   }

   return 0;
}

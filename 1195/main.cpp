#include <cstdint>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string_view>
#include <array>

int main()
{
   std::vector< char > data;
   while( true )
   {
      char sym = std::getchar();
      if( sym == EOF )
         break;
      if( sym != 'X' && sym != 'O' && sym != '#' )
         continue;
      data.push_back( sym );
   }

   std::vector< uint32_t > ids = {
      0, 3, 6,
      1, 4, 7,
      2, 5, 8,
      0, 4, 8,
      2, 4, 6
   };

   for( auto i : ids )
      data.push_back( data[ i ] );

   auto calc = [ & ]()
   {
      constexpr std::array< std::string_view, 3 > const SEARCH_IN = {
         "YY#",
         "Y#Y",
         "#YY"
      };

      uint32_t result = 0;
      for( uint32_t i = 0; i < data.size(); i += 3 )
      {
         std::string_view sv( data.data() + i, 3 );
         if( std::find( SEARCH_IN.begin(), SEARCH_IN.end(), sv ) != SEARCH_IN.end() )
            ++result;
      }
      return result;
   };

   std::replace( data.begin(), data.end(), 'X', 'Y' );
   uint32_t x_count = calc();

   std::replace( data.begin(), data.end(), 'Y', 'X' );
   std::replace( data.begin(), data.end(), 'O', 'Y' );
   uint32_t o_count = calc();

   if( x_count > 0 )
      std::printf( "Crosses win\n" );
   else if( o_count > 1 )
      std::printf( "Ouths win\n" );
   else
      std::printf( "Draw\n" );

   return 0;
}

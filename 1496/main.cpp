#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
   uint32_t N;
   std::cin >> N;

   std::unordered_map< std::string, uint16_t > cache;
   for( uint32_t i = 0; i < N; ++i )
   {
      std::string s;
      std::cin >> s;
      auto it = cache.find( s );
      if( it != cache.end() )
         it->second += 1;
      else
         cache[ s ] = 1;
   }

   for( auto const& c : cache )
      if( c.second > 1 )
         std::cout << c.first << std::endl;

   return 0;
}

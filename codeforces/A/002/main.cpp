#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>

int main()
{
   int n;
   std::cin >> n;
   std::unordered_map< std::string, long > names;
   std::pair< std::string, long > max = std::make_pair( std::string(), std::numeric_limits< long >::min() );

   for( int i = 0; i < n; ++i )
   {
      std::string name;
      long score;
      std::cin >> name >> score;

      auto it = names.find( name );
      if( it == names.end() )
         it = names.insert( std::make_pair( std::move( name ), 0 ) ).first;
      it->second += score;

      if( max.second < it->second )
         max = *it;
   }

   std::cout << max.first << std::endl;

   return 0;
}

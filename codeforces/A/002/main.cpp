#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>

int main()
{
   int n;
   std::cin >> n;
   std::unordered_map< std::string, long > names;
   std::vector< std::pair< std::string, long > > scores;

   // проходим игру
   for( int i = 0; i < n; ++i )
   {
      std::string name;
      long score;
      std::cin >> name >> score;

      auto it = names.find( name );
      if( it == names.end() )
         it = names.insert( std::make_pair( std::move( name ), 0 ) ).first;
      it->second += score;

      scores.push_back( *it );
   }

   // вычисляем максимум
   long max = std::numeric_limits< long >::min();
   for( auto it = names.begin(); it != names.end(); ++it )
   {
     if( max < it->second )
        max = it->second;
   }

   std::pair< size_t, std::string > result = std::make_pair( scores.size(), std::string() );
   for( auto it = names.begin(); it != names.end(); ++it )
   {
     if( it->second == max )
     {
       auto it_score = std::find_if( scores.begin(), scores.end(), [&]( std::pair< std::string, long > const& item ){
         return ( item.second >= max && item.first == it->first );
       });
       size_t distance = std::distance( scores.begin(), it_score );
       if( it_score != scores.end() && result.first > distance )
       {
         result.first = distance;
         result.second = it->first;
       }
     }
   }

   std::cout << result.second << std::endl;

   return 0;
}

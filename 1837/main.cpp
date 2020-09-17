#include <iostream>
#include <cinttypes>
#include <string>
#include <map>
#include <limits>
#include <unordered_set>

int main()
{
   uint32_t N;
   std::cin >> N;

   std::map< std::string, std::pair< uint32_t, std::unordered_set< std::string > > > people;

   for( uint32_t i = 0; i < N; ++i )
   {
      std::string s1, s2, s3;
      std::cin >> s1 >> s2 >> s3;

      auto& p1 = people[ s1 ];
      p1.first = std::numeric_limits< uint32_t >::max();
      p1.second.insert( s2 );
      p1.second.insert( s3 );

      auto& p2 = people[ s2 ];
      p2.first = std::numeric_limits< uint32_t >::max();
      p2.second.insert( s1 );
      p2.second.insert( s3 );

      auto& p3 = people[ s3 ];
      p3.first = std::numeric_limits< uint32_t >::max();
      p3.second.insert( s1 );
      p3.second.insert( s2 );
   }

   auto isenbaev_it = people.find( "Isenbaev" );
   if( isenbaev_it != people.end() )
   {
      isenbaev_it->second.first = 0;
      std::unordered_set< std::string > processed;

      while( processed.size() < people.size() )
      {
         std::string current_name;
         uint32_t current_value = std::numeric_limits< uint32_t >::max();
         for( auto const& person : people )
         {
            if( processed.find( person.first ) != processed.end() )
               continue;
            if( person.second.first < current_value  )
            {
               current_name = person.first;
               current_value = person.second.first;
            }
         }
         if( current_name.empty() )
            break;
         processed.insert( current_name );

         auto const& current_person = people[ current_name ];
         for( auto const& name : current_person.second )
         {
            auto& person = people[ name ];
            if( person.first > current_person.first + 1 )
               person.first = current_person.first + 1;
         }
      }
   }

   for( auto const& person : people )
   {
      std::cout << person.first << " ";

      if( person.second.first != std::numeric_limits< uint32_t >::max() )
         std::cout << person.second.first;
      else
         std::cout << "undefined";

      std::cout << std::endl;
   }

   return 0;
}

#include <iostream>
#include <stdint.h>
#include <string>
#include <cctype>
#include <unordered_map>

int main()
{
   std::unordered_map< char, char > map;

   std::string s1, s2;
   std::cin >> s1 >> s2;

   for( int16_t i = 0; i < s1.size(); ++i )
   {
      map.emplace( std::make_pair( s1[i], s2[i] ) );
      map.emplace( std::make_pair( std::toupper(s1[i]), std::toupper(s2[i]) ) );
   }

   std::string s3;
   std::cin >> s3;

   for( char& c : s3 )
   {
      if( map.find( c ) != map.end() )
         c = map[c];
   }

   std::cout << s3 << std::endl;

   return 0;
}

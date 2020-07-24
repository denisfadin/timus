#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <algorithm>

int main()
{
   std::vector< std::string > strs;

   size_t max = 0;

   while( true )
   {
      std::string s;
      std::getline( std::cin, s );

      if( std::cin.eof() )
         break;

      max = std::max( s.size(), max );

      strs.emplace_back( std::move(s) );
   }

   for( size_t i = 0; i < max + 2; ++i )
      std::cout << '*';
   std::cout << std::endl;

   bool round_left = false;
   for( std::string const& s : strs )
   {
      std::cout << '*';
      auto d = max - s.size();
      auto left = d >> 1;
      auto right = d >> 1;
      if( d % 2 )
      {
         if( round_left )
            left += 1;
         else
            right += 1;
         round_left = !round_left;
      }

      for( size_t i = 0; i < left; ++i )
         std::cout << ' ';

      std::cout << s;

      for( size_t i = 0; i < right; ++i )
         std::cout << ' ';

      std::cout << '*' << std::endl;
   }

   for( size_t i = 0; i < max + 2; ++i )
      std::cout << '*';
   std::cout << std::endl;

   return 0;
}

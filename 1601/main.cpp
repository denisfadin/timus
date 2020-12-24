#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

int main()
{
   std::ios_base::sync_with_stdio( false );

   bool need_upper = true;
   std::string line;
   while( std::getline( std::cin, line ) )
   {
      std::transform( line.begin(), line.end(), line.begin(), [ &need_upper ]( char c )
      {
         if( std::isalpha( c ) )
         {
            if( need_upper )
            {
               need_upper = false;
               return static_cast< char >( std::toupper( c ) );
            }
            else
               return static_cast< char >( std::tolower( c ) );
         }
         else
         {
            switch( c )
            {
               case '.':
               case '!':
               case '?':
                  need_upper = true;
                  break;
            }
            return c;
         }
      });

      std::cout << line << std::endl;
   }
}

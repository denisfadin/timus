#include <cstdint>
#include <string>
#include <iostream>

inline uint32_t GetCost( char sym )
{
   switch( sym )
   {
      case ' ':
      case '.':
         return 1;
      case ',':
         return 2;
      case '!':
         return 3;
      default:
         return static_cast< uint32_t >( ((sym - 'a') % 3) + 1 );
   }
}

int main()
{
   std::string s;
   std::getline( std::cin, s );

   uint32_t result = 0;
   for( char sym : s )
      result += GetCost( sym );

   std::cout << result << std::endl;

   return 0;
}

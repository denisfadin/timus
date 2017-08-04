#include <iostream>
#include <stdint.h>
#include <string>

int main()
{
   int16_t N;
   std::cin >> N;

   std::string s;
   s.resize( 1+N );
   std::cin.read( &s[0], 1+N );

   int16_t result = 0, word_result = 0;

   for( char c : s )
   {
      if( c == ' ' )
      {
         result = std::max( result, word_result );
         word_result = 0;
      }
      else if( c >= 'A' && c <= 'Z' )
         ++word_result;
   }
   result = std::max( result, word_result );

   std::cout << result << std::endl;

   return 0;
}

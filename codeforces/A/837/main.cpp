#include <iostream>
#include <stdint.h>
#include <string>

int main()
{
   int16_t N;
   std::cin >> N;

   std::string s;

   int16_t result = 0;
   while( std::cin >> s )
   {
      int16_t word_result = 0;
      for( auto c : s )
         if( std::isupper( c ) )
            ++word_result;

      result = std::max( result, word_result );
   }

   std::cout << result << std::endl;

   return 0;
}

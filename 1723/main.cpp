#include <iostream>
#include <string>
#include <algorithm>
#include <cinttypes>

int main()
{
   std::string str;
   std::cin >> str;

   std::sort( str.begin(), str.end() );

   char result = 0;
   uint16_t result_count = 0;

   char curr_sym = 0;
   uint16_t curr_sym_count = 0;
   for( auto sym : str )
   {
      if( sym == curr_sym )
         ++curr_sym_count;
      else
      {
         curr_sym = sym;
         curr_sym_count = 1;
      }

      if( curr_sym_count > result_count )
      {
         result = sym;
         result_count = curr_sym_count;
      }
   }

   std::cout << result << std::endl;

   return 0;
}

#include <iostream>
#include <cinttypes>
#include <string>

int main()
{
   int32_t x;
   std::cin >> x;

   std::string result = "YES";

   std::string s = std::to_string( x );
   auto i = std::begin( s );
   auto j = std::end( s );
   --j;
   while( *j == '0' )
      --j;
   while( i < j )
   {
      if( *i != *j )
      {
         result = "NO";
         break;
      }
      ++i;
      --j;
   }

   std::cout << result << std::endl;

   return 0;
}

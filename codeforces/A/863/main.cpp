#include <iostream>
#include <cinttypes>
#include <string>

int main()
{
   int32_t x;
   std::cin >> x;

   std::string s = std::to_string( x );
   while( s.size() && s.back() == '0' )
      s.pop_back();

   std::string result = "YES";

   while( s.size() )
   {
      if( s.front() != s.back() )
      {
         result = "NO";
         break;
      }

      s.erase( 0, 1 );
      if( s.size() )
         s.pop_back();
   }

   std::cout << result << std::endl;

   return 0;
}

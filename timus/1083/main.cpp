#include <cstdint>
#include <iostream>
#include <string>

int main()
{
   int32_t n;
   std::cin >> n;

   std::string s;
   std::cin >> s;

   int32_t k = s.size();

   int32_t result = n;
   while( true )
   {
      n -= k;
      if( n <= 0 )
         break;

      result *= n;
   }

   std::cout << result << std::endl;

   return 0;
}

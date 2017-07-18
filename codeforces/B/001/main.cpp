#include <iostream>
#include <cstdint>
#include <string>

int main()
{
   int32_t N;
   std::cin >> N;

   std::string s;

   for( int32_t i = 0; i < N; ++i )
   {
      std::cin >> s;

      if( s.at( 0 ) == 'R' && s.at( 1 ) >= '1' && s.at( 1 ) <= '9' && s.find( 'C' ) != std::string::npos )
      {
         std::cout << "RXCY" << std::endl;
      }
      else
      {
         std::cout << "A1" << std::endl;
      }
   }

   return 0;
}

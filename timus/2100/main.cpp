#include <iostream>
#include <cinttypes>
#include <string>

int main()
{
   uint32_t N;
   std::cin >> N;

   uint32_t people = 2;
   for( uint32_t i = 0; i < N; ++i )
   {
      std::string s;
      std::cin >> s;
      ++people;
      if( s.find( "+one" ) != std::string::npos )
         ++people;
   }

   if( people == 13 )
      ++people;

   std::cout << people*100 << std::endl;
}

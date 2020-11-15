#include <cstdint>
#include <iostream>
#include <string>
#include <algorithm>

constexpr std::string_view const TYPE1{ "Emperor Penguin" };
constexpr std::string_view const TYPE2{ "Little Penguin" };
constexpr std::string_view const TYPE3{ "Macaroni Penguin" };

int main()
{
   uint32_t N;
   std::cin >> N;

   uint32_t t1 = 0, t2 = 0, t3 = 0;

   std::cin >> std::ws;
   for( uint32_t i = 0; i < N; ++i )
   {
      std::string type;
      std::getline( std::cin, type );

      if( type == TYPE1 )
         ++t1;
      else if( type == TYPE2 )
         ++t2;
      else // TYPE3
         ++t3;
   }

   std::string_view result = TYPE3;
   if( t2 > t3 )
      result = TYPE2;
   if( t1 > t2 && t1 > t3 )
      result = TYPE1;

   std::cout << result << std::endl;

   return 0;
}

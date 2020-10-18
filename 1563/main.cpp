#include <cstdint>
#include <unordered_set>
#include <string>
#include <iostream>

int main()
{
   uint32_t N;
   std::cin >> N;
   std::cin >> std::ws;

   std::unordered_set< std::string > markets;
   for( uint32_t i = 0; i < N; ++i )
   {
      std::string s;
      std::getline( std::cin, s );
      markets.insert( std::move( s ) );
   }

   std::cout << N - markets.size() << std::endl;

   return 0;
}

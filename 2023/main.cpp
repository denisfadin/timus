#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
   std::unordered_map< char, int32_t > POSITIONS {
      {'A', 1},
      {'B', 2},
      {'D', 3},
      {'G', 3},
      {'J', 3},
      {'P', 1},
      {'O', 1},
      {'M', 2},
      {'K', 3},
      {'R', 1},
      {'S', 2},
      {'T', 3},
      {'W', 3}
   };

   uint32_t N;
   std::cin >> N;

   uint32_t result = 0;

   int32_t curr_pos = 1;
   for( uint32_t i = 0; i < N; ++i )
   {
      std::string s;
      std::cin >> s;

      auto new_pos = POSITIONS[ s.at(0) ];

      result += new_pos > curr_pos ? new_pos - curr_pos : curr_pos - new_pos;

      curr_pos = new_pos;
   }

   std::cout << result << std::endl;

   return 0;
}

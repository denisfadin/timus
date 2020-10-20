#include <cstdint>
#include <iostream>

uint64_t Do( uint32_t N )
{
   if( N < 3 )
      return 2;

   uint64_t end_white = 1;
   uint64_t end_red = 1;
   uint64_t end_blue_after_white = 1;
   uint64_t end_blue_after_red = 1;

   for( uint64_t i = 3; i < N; ++i )
   {
      auto e_w = end_white;
      auto e_r = end_red;
      auto e_b_a_w = end_blue_after_white;
      auto e_b_a_r = end_blue_after_red;

      end_white = e_r + e_b_a_r;
      end_red = e_w + e_b_a_w;
      end_blue_after_white = e_w;
      end_blue_after_red = e_r;
   }

   return end_white + end_red + end_blue_after_white + end_blue_after_red;
}

int main()
{
   uint32_t N;
   std::cin >> N;

   uint64_t result = Do( N );

   std::cout << result << std::endl;

   return 0;
}

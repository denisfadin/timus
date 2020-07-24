#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
   char s_x, s_y, t_x, t_y;
   std::cin >> s_x >> s_y >> t_x >> t_y;

   int curr_x = s_x - 'a', curr_y = s_y - '1';
   int finish_x = t_x - 'a', finish_y = t_y - '1';

   std::cout << std::max( std::abs( curr_x - finish_x ), std::abs( curr_y - finish_y ) ) << std::endl;

   while( curr_x != finish_x || curr_y != finish_y )
   {
      if( curr_x < finish_x )
      {
         ++curr_x;
         std::cout << 'R';
      }
      else if( curr_x > finish_x )
      {
         --curr_x;
         std::cout << 'L';
      }

      if( curr_y < finish_y )
      {
         ++curr_y;
         std::cout << 'U';
      }
      else if( curr_y > finish_y )
      {
         --curr_y;
         std::cout << 'D';
      }

      std::cout << std::endl;
   }

   return 0;
}

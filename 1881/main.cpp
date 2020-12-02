#include <cstdint>
#include <iostream>
#include <string>

int main()
{
   uint16_t H, W, N;
   std::cin >> H >> W >> N;

   uint16_t result_lines_count = 0;

   uint16_t curr_line_size = 0;
   std::string word;
   for( uint16_t i = 0; i < N; ++i )
   {
      std::cin >> word;
      if( curr_line_size + ( curr_line_size ? 1 : 0 ) + word.size() > W )
      {
         ++result_lines_count;
         curr_line_size = 0;
      }
      else if( curr_line_size )
         ++curr_line_size;

      curr_line_size += word.size();
   }
   if( curr_line_size )
      ++result_lines_count;

   std::cout << result_lines_count / H + (( result_lines_count % H ) ? 1 : 0) << std::endl;

   return 0;
}

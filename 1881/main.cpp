#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <cstring>
#include <array>

int main()
{
   uint16_t H, W, N;
   std::scanf( "%" SCNu16 "%" SCNu16 "%" SCNu16, &H, &W, &N );

   uint16_t result_lines_count = 0;

   uint16_t curr_line_size = 0;
   std::array< char, 101 > word;
   for( uint16_t i = 0; i < N; ++i )
   {
      std::scanf( "%s", word.data() );
      auto word_size = std::strlen( word.data() );
      if( curr_line_size + ( curr_line_size ? 1 : 0 ) + word_size > W )
      {
         ++result_lines_count;
         curr_line_size = 0;
      }
      else if( curr_line_size )
         ++curr_line_size;

      curr_line_size += word_size;
   }
   if( curr_line_size )
      ++result_lines_count;

   std::printf( "%" PRIu16 "\n", result_lines_count / H + (( result_lines_count % H ) ? 1 : 0));

   return 0;
}

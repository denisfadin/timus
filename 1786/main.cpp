#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <array>
#include <string_view>
#include <cstring>
#include <limits>
#include <algorithm>
#include <cctype>

int main()
{
   constexpr std::string_view const SANDRO = "Sandro";

   std::array< char, 201 > buffer;
   std::scanf( "%s", buffer.data() );
   uint32_t str_size = std::strlen( buffer.data() );

   uint32_t result = std::numeric_limits< uint32_t >::max();
   for( uint32_t i = 0; i + SANDRO.size() <= str_size; ++i )
   {
      uint32_t res = 0;
      for( uint32_t j = 0; j < SANDRO.size(); ++j )
      {
         char c_src = buffer[ i + j ];
         char c_dest = SANDRO[ j ];
         if( std::isupper( c_dest ) )
         {
            if( !std::isupper( c_src ) )
            {
               c_src = std::toupper( c_src );
               res += 5;
            }
         }
         else
         {
            if( std::isupper( c_src ) )
            {
               c_src = std::tolower( c_src );
               res += 5;
            }
         }
         if( c_src != c_dest )
            res += 5;
      }

      result = std::min( result, res );
   }

   std::printf( "%" PRIu32 "\n", result );

   return 0;
}

#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <vector>
#include <string_view>

int main()
{
   std::vector< std::string_view > numbers = {
      "16",
      "06",
      "68",
      "88"
   };

   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   if( N > numbers.size() )
      std::printf( "Glupenky Pierre" );
   else
   {
      for( uint16_t i = 0; i < N; ++i )
         std::printf( "%.*s ", static_cast< int>( numbers[ i ].size() ), numbers[ i ].data() );
   }

   std::printf( "\n" );

   return 0;
}

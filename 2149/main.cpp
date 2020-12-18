#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <string_view>

int main()
{
   std::string_view const gl = "<@..";

   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   std::vector< char > buffer( N * (gl.size() + 1) + 1 );
   std::scanf( "%s", buffer.data() );

   std::vector< bool > data( N );
   for( uint16_t i = 0; i < N; ++i )
   {
      std::string_view s( buffer.data() + i * ( gl.size() + 1 ), gl.size() );
      data[ i ] = ( s == gl );
   }

   uint16_t result = N;

   {
      uint16_t res1 = 0, res2 = 0;
      for( uint16_t i = 0; i < N; i += 2 )
      {
         if( data[ i ] )
            ++res1;
         else
            ++res2;

         if( !data[ i+1 ] )
            ++res1;
         else
            ++res2;
      }

      if( result > res1 )
         result = res1;
      if( result > res2 )
         result = res2;
   }

   {
      uint16_t res1 = 0, res2 = 0;
      for( uint16_t i = 0, j = N-1; i < j; ++i, --j )
      {
         if( data[ i ] )
            ++res1;
         else
            ++res2;

         if( !data[ j ] )
            ++res1;
         else
            ++res2;
      }

      if( result > res1 )
         result = res1;
      if( result > res2 )
         result = res2;
   }

   std::printf( "%" PRIu16 "\n", result );

   return 0;
}

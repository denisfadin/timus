#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

int main()
{
   std::vector< char > str( 200001, 0 );
   std::scanf( "%s", &str[ 0 ] );

   size_t result_size = 0;
   for( size_t i = 0; i < str.size(); ++i )
   {
      if( result_size > 0 && str[ i ] == str[ result_size - 1 ] )
         --result_size;
      else
      {
         str[ result_size ] = str[ i ];
         ++result_size;
      }
   }

   std::printf( "%.*s\n", static_cast< int >( result_size ), &str[ 0 ] );

   return 0;
}

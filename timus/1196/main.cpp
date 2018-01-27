#include <cstdio>
#include <cinttypes>
#include <vector>

int main()
{
   uint32_t n;
   scanf( "%" SCNu32, &n );

   std::vector< bool > buf;
   buf.resize( n );
   for( uint32_t i = 0; i < n; ++i )
      scanf( "%" SCNu32, &buf[i] );

   uint32_t m;
   scanf( "%" SCNu32, &m );

   uint32_t result = 0;
   for( uint32_t i = 0; i < m; ++i )
   {
      uint32_t x;
      scanf( "%" SCNu32, &x );

      if( std::binary_search( std::begin(buf), std::end(buf), x ) )
         ++result;
   }

   printf( "%" PRIu32 "\n", result );

   return 0;
}

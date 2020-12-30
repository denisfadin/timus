#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< uint32_t > data( N );
   for( uint32_t i = 0; i < N; ++i )
      std::scanf( "%" SCNu32, &data[ i ] );

   std::sort( data.begin(), data.end(), std::greater< uint32_t >() );

   double result = data[ 0 ];
   for( uint32_t i = 1; i < N; ++i )
      result = 2 * std::sqrt( result * static_cast< double >( data[ i ] ) );

   std::printf( "%.2lf\n", result );

   return 0;
}

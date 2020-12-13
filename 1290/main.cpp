#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

std::vector< uint32_t > Do( std::vector< uint32_t > const& data )
{
   if( data.empty() )
      return std::vector< uint32_t >{};

   uint16_t max = data[ 0 ];
   for( uint32_t const& d : data )
      if( max < d )
         max = d;

   if( max <= 1 )
      return std::vector< uint32_t >{ static_cast< uint32_t >( data.size() ) };

   std::vector< uint32_t > result( max, 0 );

   for( uint32_t const& d : data )
      result[ d - 1 ] += 1;
   result[ 0 ] = data.size();

   if( result.size() > 2 )
   {
      for( uint32_t i = result.size() - 2; i > 0; i-- )
         result[ i ] += result[ i + 1 ];
   }

   return result;
}

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< uint32_t > data( N, 0 );
   for( uint32_t i = 0; i < N; ++i )
      std::scanf( "%" SCNu32, &data[ i ] );

   auto result = Do( Do( data ) );
   for( uint32_t r : result )
      std::printf( "%" PRIu32 "\n", r );

   return 0;
}

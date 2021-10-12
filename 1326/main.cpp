#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <limits>
#include <map>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::map< uint32_t, uint32_t > predefined;

   for( uint32_t i = 0; i < N; ++i )
   {
      uint32_t sum;
      std::scanf( "%" SCNu32, &sum );

      uint32_t bits = ( 1 << i );
      predefined[ bits ] = sum;
   }

   uint32_t M;
   std::scanf( "%" SCNu32, &M );

   for( uint32_t i = 0; i < M; ++i )
   {
      uint32_t sum;
      std::scanf( "%" SCNu32, &sum );

      uint32_t k;
      std::scanf( "%" SCNu32, &k );

      uint32_t bits = 0;
      for( uint32_t j = 0; j < k; ++j )
      {
         uint32_t num;
         std::scanf( "%" SCNu32, &num );
         bits |= ( 1 << ( num - 1 ) );
      }

      if( predefined.find( bits ) != predefined.end() )
         predefined[ bits ] = std::min( predefined[ bits ], sum );
      else
         predefined[ bits ] = sum;
   }

   uint32_t K;
   std::scanf( "%" SCNu32, &K );

   uint32_t TO_BY = 0;
   for( uint32_t i = 0; i < K; ++i )
   {
      uint32_t num;
      std::scanf( "%" SCNu32, &num );
      TO_BY |= ( 1 << ( num - 1 ) );
   }

   std::vector< uint32_t > DP( 1 << N, std::numeric_limits< uint32_t >::max() );

   for( auto it = predefined.begin(); it != predefined.end(); ++it )
      DP[ it->first ] = it->second;

   for( uint32_t i = 1; i < ( 1 << N ); ++i )
   {
      if( DP[ i ] == std::numeric_limits< uint32_t >::max() )
         continue;

      if( predefined.find( i ) != predefined.end() )
      {
         for( uint32_t j = 1; j < i; ++j )
         {
            if( DP[ j ] == std::numeric_limits< uint32_t >::max() )
               continue;

            DP[ i | j ] = std::min( DP[ i | j ], DP[ j ] + DP[ i ] );
         }
      }
      else
      {
         for( auto it = predefined.begin(); it != predefined.end(); ++it )
         {
            if( it->first > i )
               break;

            DP[ i | it->first ] = std::min( DP[ i | it->first ], DP[ i ] + it->second );
         }
      }
   }

   uint32_t result = std::numeric_limits< uint32_t >::max();

   for( uint32_t i = 1; i < ( 1 << N ); ++i )
   {
      if( ( i & TO_BY ) != TO_BY )
         continue;

      result = std::min( result, DP[ i ] );
   }

   std::printf( "%" PRIu32 "\n", result );

   return 0;
}

#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

int main()
{
   uint32_t const MOD = 1000000007;

   uint_fast16_t N, A, B;
   std::scanf( "%" SCNuFAST16 "%" SCNuFAST16 "%" SCNuFAST16, &N, &A, &B );

   std::vector< uint32_t > cache_a( N + 1, 0 );
   cache_a[ 0 ] = 1;

   std::vector< uint32_t > cache_b( N + 1, 0 );
   cache_b[ 0 ] = 1;

   for( uint_fast16_t i = 1; i <= N; ++i )
   {
      uint64_t a_i = 0;
      for( uint16_t j = i - 1; i - j <= A; --j )
      {
         a_i += cache_b[ j ];
         if( j == 0 )
            break;
      }
      cache_a[ i ] = static_cast< uint32_t >( a_i % MOD );

      uint64_t b_i = 0;
      for( uint_fast16_t j = i - 1; i - j <= B; --j )
      {
         b_i += cache_a[ j ];
         if( j == 0 )
            break;
      }
      cache_b[ i ] = static_cast< uint32_t >( b_i % MOD );
   }

   std::printf( "%" PRIu32 "\n", ( cache_a[ N ] + cache_b[ N ] ) % MOD );

   return 0;
}

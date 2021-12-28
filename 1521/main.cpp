#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

void build( std::vector< uint32_t >& tree,
                         uint32_t v,
                         uint32_t tl,
                         uint32_t tr )
{
   if( tl == tr )
      tree[ v ] = 1;
   else
   {
      uint32_t tm = ( tl + tr ) >> 1;
      build( tree, v << 1, tl, tm );
      build( tree, (v << 1) + 1, tm + 1, tr );
      tree[ v ] = tree[ v << 1 ] + tree[ (v << 1) + 1 ];
   }
}

void update( std::vector< uint32_t >& tree,
             uint32_t v,
             uint32_t tl,
             uint32_t tr,
             uint32_t pos )
{
   if( tl == tr )
      tree[ v ] = 0;
   else
   {
      uint32_t tm = ( tl + tr ) >> 1;
      if( pos <= tm )
         update( tree, v << 1, tl, tm, pos );
      else
         update( tree, (v << 1) + 1, tm + 1, tr, pos );
      tree[ v ] = tree[ v << 1 ] + tree[ (v << 1) + 1 ];
   }
}

uint32_t find_kth( std::vector< uint32_t > const& tree,
                   uint32_t v,
                   uint32_t tl,
                   uint32_t tr,
                   uint32_t k )
{
   if( tl == tr )
      return tl;
   uint32_t tm = ( tl + tr ) >> 1;
   if( tree[ v << 1 ] >= k )
      return find_kth( tree, v << 1, tl, tm, k );
   else
      return find_kth( tree, (v << 1) + 1, tm + 1, tr, k - tree[ v << 1 ] );
}

int main()
{
   uint32_t N, K;
   std::scanf( "%" SCNu32 " %" SCNu32, &N, &K );

   std::vector< uint32_t > tree( 4*N, 0 );
   build( tree, 1, 1, N );

   uint32_t pos = K;
   for( uint32_t i = 0; i < N; ++i )
   {
      pos %= tree[ 1 ];
      if( pos == 0 )
         pos = tree[ 1 ];
      uint32_t idx = find_kth( tree, 1, 1, N, pos );
      std::printf( "%" PRIu32 " ", idx );
      update( tree, 1, 1, N, idx );
      pos = pos - 1 + K;
   }
   std::printf("\n");

   return 0;
}

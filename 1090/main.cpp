#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

void st_update( std::vector< uint32_t >& segment_tree,
                uint32_t v,
                uint32_t tl, uint32_t tr,
                uint32_t pos )
{
   if( tl == tr )
      segment_tree[ v ] = 1;
   else
   {
      uint32_t tm = ( tl + tr ) >> 1;
      if( pos <= tm )
         st_update( segment_tree, (v<<1)+1, tl, tm, pos );
      else
         st_update( segment_tree, (v<<1)+2, tm+1, tr, pos );
      segment_tree[ v ] = segment_tree[ (v<<1)+1 ] + segment_tree[ (v<<1)+2 ];
   }
}

uint32_t st_sum( std::vector< uint32_t >& segment_tree,
                 uint32_t v,
                 uint32_t tl, uint32_t tr,
                 uint32_t l, uint32_t r )
{
   if( l > r )
      return 0;

   if( l == tl && r == tr )
      return segment_tree[ v ];

   uint32_t tm = ( tl + tr ) >> 1;
   return st_sum( segment_tree, (v<<1)+1, tl, tm, l, std::min( tm, r ) ) +
          st_sum( segment_tree, (v<<1)+2, tm+1, tr, std::max( tm+1, l ), r );
}

int main()
{
   uint32_t N, K;
   std::scanf( "%" SCNu32 " %" SCNu32, &N, &K );

   uint32_t max_sum = 0;
   uint32_t max_k = 1;

   std::vector< uint32_t > segment_tree( 4*(N+1) );
   for( uint32_t k = 1; k <= K; ++k )
   {
      std::fill( segment_tree.begin(), segment_tree.end(), 0 );

      uint32_t sum = 0;
      for( uint32_t i = 0; i < N; ++i )
      {
         uint32_t h;
         std::scanf( "%" SCNu32, &h );

         if( h < N )
            sum += st_sum( segment_tree, 0, 0, N, h+1, N );
         st_update( segment_tree, 0, 0, N, h );
      }

      if( sum > max_sum )
      {
         max_sum = sum;
         max_k = k;
      }
   }

   std::printf( "%" PRIu32 "\n", max_k );

   return 0;
}

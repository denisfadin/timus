#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

uint32_t next_highest_power_of_2( uint32_t v )
{
   v--;
   v |= v >> 1;
   v |= v >> 2;
   v |= v >> 4;
   v |= v >> 8;
   v |= v >> 16;
   v++;
   return v;
}

uint32_t segment_tree_size( uint32_t N )
{
   uint32_t size = N * N * N;
   uint32_t result = 1;
   while( size != 1 )
   {
      result += size;
      size /= 8;
   }
   return result;
}

void st_update( std::vector< uint64_t >& segment_tree,
                uint32_t v,
                uint32_t xl, uint32_t xr, uint32_t x,
                uint32_t yl, uint32_t yr, uint32_t y,
                uint32_t zl, uint32_t zr, uint32_t z,
                int32_t diff )
{
   if( xl == xr && yl == yr && zl == zr )
      segment_tree[ v ] += diff;
   else
   {
      uint32_t xm = ( xl + xr ) / 2;
      uint32_t ym = ( yl + yr ) / 2;
      uint32_t zm = ( zl + zr ) / 2;

      if( x <= xm )
      {
         if( y <= ym )
         {
            if( z <= zm )
               st_update( segment_tree,
                          8*v+1,
                          xl, xm, x,
                          yl, ym, y,
                          zl, zm, z,
                          diff );
            else
               st_update( segment_tree,
                          8*v+4,
                          xl, xm, x,
                          yl, ym, y,
                          zm+1, zr, z,
                          diff );
         }
         else // y > ym
         {
            if( z <= zm )
               st_update( segment_tree,
                          8*v+2,
                          xl, xm, x,
                          ym+1, yr, y,
                          zl, zm, z,
                          diff );
            else
               st_update( segment_tree,
                          8*v+3,
                          xl, xm, x,
                          ym+1, yr, y,
                          zm+1, zr, z,
                          diff );
         }
      }
      else // x > xm
      {
         if( y <= ym )
         {
            if( z <= zm )
               st_update( segment_tree,
                          8*v+5,
                          xm+1, xr, x,
                          yl, ym, y,
                          zl, zm, z,
                          diff );
            else
               st_update( segment_tree,
                          8*v+8,
                          xm+1, xr, x,
                          yl, ym, y,
                          zm+1, zr, z,
                          diff );
         }
         else // y > ym
         {
            if( z <= zm )
               st_update( segment_tree,
                          8*v+6,
                          xm+1, xr, x,
                          ym+1, yr, y,
                          zl, zm, z,
                          diff );
            else
               st_update( segment_tree,
                          8*v+7,
                          xm+1, xr, x,
                          ym+1, yr, y,
                          zm+1, zr, z,
                          diff );
         }
      }

      segment_tree[ v ] = 0;
      for( uint32_t i = 1; i <= 8; ++i )
         segment_tree[ v ] += segment_tree[ 8*v + i ];
   }
}

uint64_t st_sum( std::vector< uint64_t >& segment_tree,
                 uint32_t v,
                 uint32_t txl, uint32_t txr, uint32_t xl, uint32_t xr,
                 uint32_t tyl, uint32_t tyr, uint32_t yl, uint32_t yr,
                 uint32_t tzl, uint32_t tzr, uint32_t zl, uint32_t zr )
{
   if( xl > xr || yl > yr || zl > zr )
      return 0;

   if( txl == xl && txr == xr &&
       tyl == yl && tyr == yr &&
       tzl == zl && tzr == zr )
   {
      return segment_tree[ v ];
   }

   uint32_t txm = ( txl + txr ) / 2;
   uint32_t tym = ( tyl + tyr ) / 2;
   uint32_t tzm = ( tzl + tzr ) / 2;

   uint64_t result = 0;

   // xl, yl, zl => 1
   result += st_sum( segment_tree,
                     8*v+1,
                     txl, txm, xl, std::min( txm, xr ),
                     tyl, tym, yl, std::min( tym, yr ),
                     tzl, tzm, zl, std::min( tzm, zr ) );

   // xl, yl, zr => 4
   result += st_sum( segment_tree,
                     8*v+4,
                     txl, txm, xl, std::min( txm, xr ),
                     tyl, tym, yl, std::min( tym, yr ),
                     tzm+1, tzr, std::max( tzm+1, zl ), zr );

   // xl, yr, zl => 2
   result += st_sum( segment_tree,
                     8*v+2,
                     txl, txm, xl, std::min( txm, xr ),
                     tym+1, tyr, std::max( tym+1, yl ), yr,
                     tzl, tzm, zl, std::min( tzm, zr ) );

   // xl, yr, zr => 3
   result += st_sum( segment_tree,
                     8*v+3,
                     txl, txm, xl, std::min( txm, xr ),
                     tym+1, tyr, std::max( tym+1, yl ), yr,
                     tzm+1, tzr, std::max( tzm+1, zl ), zr );

   // xr, yl, zl => 5
   result += st_sum( segment_tree,
                     8*v+5,
                     txm+1, txr, std::max( txm+1, xl ), xr,
                     tyl, tym, yl, std::min( tym, yr ),
                     tzl, tzm, zl, std::min( tzm, zr ) );

   // xr, yl, zr => 8
   result += st_sum( segment_tree,
                     8*v+8,
                     txm+1, txr, std::max( txm+1, xl ), xr,
                     tyl, tym, yl, std::min( tym, yr ),
                     tzm+1, tzr, std::max( tzm+1, zl ), zr );

   // xr, yr, zl => 6
   result += st_sum( segment_tree,
                     8*v+6,
                     txm+1, txr, std::max( txm+1, xl ), xr,
                     tym+1, tyr, std::max( tym+1, yl ), yr,
                     tzl, tzm, zl, std::min( tzm, zr ) );

   // xr, yr, zr => 7
   result += st_sum( segment_tree,
                     8*v+7,
                     txm+1, txr, std::max( txm+1, xl ), xr,
                     tym+1, tyr, std::max( tym+1, yl ), yr,
                     tzm+1, tzr, std::max( tzm+1, zl ), zr );

   return result;
}

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   N = next_highest_power_of_2( N );

   std::vector< uint64_t > segment_tree( segment_tree_size( N ), 0 );

   while( true )
   {
      uint32_t type;
      std::scanf( "%" SCNu32, &type );
      if( type == 1 ) // update
      {
         uint32_t x, y, z;
         int32_t k;
         std::scanf( "%" SCNu32 " %" SCNu32 " %" SCNu32 " %" SCNd32, &x, &y, &z, &k );

         st_update( segment_tree,
                    0,
                    0, N-1, x,
                    0, N-1, y,
                    0, N-1, z,
                    k );

         // std::printf( "%" PRIu32 " %" PRIu32 " %" PRIu32 " %" PRId32 "\n", x, y, z, k );
         // for( uint32_t i = 0; i < segment_tree.size(); ++i )
         //    std::printf( "%" PRIu32 ": %" PRIu32 ", ", i, segment_tree[ i ] );
         // std::printf( "\n\n" );
      }
      else if( type == 2 ) // sum
      {
         uint32_t x1, y1, z1, x2, y2, z2;
         std::scanf( "%" SCNu32 " %" SCNu32 " %" SCNu32 " %" SCNu32 " %" SCNu32 " %" SCNu32,
                     &x1, &y1, &z1, &x2, &y2, &z2 );

         uint64_t result = st_sum( segment_tree,
                                   0,
                                   0, N-1, x1, x2,
                                   0, N-1, y1, y2,
                                   0, N-1, z1, z2 );

         std::printf( "%" PRIu64 "\n", result );
      }
      else
         break;
   }

   return 0;
}

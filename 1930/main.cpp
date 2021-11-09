#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <vector>
#include <queue>
#include <limits>

int main()
{
   uint32_t N, M;
   std::scanf( "%" SCNu32 " %" SCNu32, &N, &M );

   std::vector< bool > up_roads( (N+1)*(N+1), false );

   auto is_up_road = [ &up_roads, &N ]( uint32_t x, uint32_t y )
   {
      return up_roads[ x*(N+1)+y ];
   };

   for( uint32_t i = 0; i < M; ++i )
   {
      uint32_t x, y;
      std::scanf( "%" SCNu32 " %" SCNu32, &x, &y );
      up_roads[ x*(N+1)+y ] = true;
   }

   uint32_t A, B;
   std::scanf( "%" SCNu32 " %" SCNu32, &A, &B );

   std::vector< bool > checked( N+1, false );
   std::queue< uint32_t > to_process;
   checked[ A ] = true;
   to_process.push( A );

   std::vector< uint32_t > up( N+1, std::numeric_limits< uint32_t >::max() );
   up[A]=0;
   std::vector< uint32_t > down( N+1, std::numeric_limits< uint32_t >::max() );
   down[A]=0;

   while( !to_process.empty() )
   {
      auto p = to_process.front();
      to_process.pop();

      for( uint32_t i = 1; i <= N; ++i )
      {
         if( is_up_road( p, i ) )
         {
            if( !checked[ i ] )
            {
               checked[ i ] = true;
               to_process.push( i );
            }
            up[i] = std::min( up[i], up[p] );
            if( down[p] != std::numeric_limits< uint32_t >::max() )
               up[i] = std::min( up[i], down[p]+1 );
         }

         if( is_up_road( i, p ) )
         {
            if( !checked[ i ] )
            {
               checked[ i ] = true;
               to_process.push( i );
            }
            down[i] = std::min( down[i], down[p] );
            if( up[p] != std::numeric_limits< uint32_t >::max() )
               down[i] = std::min( down[i], up[p]+1 );
         }
      }
   }

   std::printf( "%" PRIu32 "\n", std::min( up[B], down[B] ) );

   return 0;
}

#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <vector>
#include <deque>
#include <limits>

int main()
{
   uint32_t N, M;
   std::scanf( "%" SCNu32 " %" SCNu32, &N, &M );

   std::vector< bool > up_roads( (N+1)*(N+1), false );
   std::vector< bool > down_roads( (N+1)*(N+1), false );

   for( uint32_t i = 0; i < M; ++i )
   {
      uint32_t x, y;
      std::scanf( "%" SCNu32 " %" SCNu32, &x, &y );
      up_roads[ x*(N+1)+y ] = true;
      down_roads[ y*(N+1)+x ] = true;
   }

   uint32_t A, B;
   std::scanf( "%" SCNu32 " %" SCNu32, &A, &B );

   std::vector< bool > checked( N+1, false );
   std::deque< uint32_t > to_process;
   to_process.push_back( A );

   std::vector< uint32_t > up( N+1, std::numeric_limits< uint32_t >::max() );
   up[A]=0;
   std::vector< uint32_t > down( N+1, std::numeric_limits< uint32_t >::max() );
   down[A]=0;

   while( !to_process.empty() )
   {
      auto p = to_process.front();
      to_process.pop_front();
      if( checked[p] )
         continue;
      checked[p] = true;

      for( uint32_t i = 1; i <= N; ++i )
      {
         if( up_roads[ p*(N+1) + i ] )
         {
            if( !checked[i] )
               to_process.push_back(i);
            up[i] = std::min( up[i], up[p] );
            if( down[p] != std::numeric_limits< uint32_t >::max() )
               up[i] = std::min( up[i], down[p]+1 );
         }

         if( down_roads[ p*(N+1) + i ] )
         {
            if( !checked[i] )
               to_process.push_back(i);
            down[i] = std::min( down[i], down[p] );
            if( up[p] != std::numeric_limits< uint32_t >::max() )
               down[i] = std::min( down[i], up[p]+1 );
         }
      }
   }

   std::printf( "%" PRIu32 "\n", std::min( up[B], down[B] ) );

   return 0;
}

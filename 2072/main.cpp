#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <vector>
#include <algorithm>

uint32_t abs_diff( uint32_t a, uint32_t b )
{
   return a > b ? a - b : b - a;
}

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< uint32_t > data( N ), idx( N );
   for( uint32_t i = 0; i < N; ++i )
   {
      std::scanf( "%" SCNu32, &data[ i ] );
      idx[ i ] = i;
   }

   std::stable_sort( idx.begin(), idx.end(), [ & ]( uint32_t idx1, uint32_t idx2 ) {
      return data[ idx1 ] < data[ idx2 ];
   });

   uint32_t last_idx_l = 0, last_idx_r = 0;
   uint64_t last_result_l = 0, last_result_r = 0;

   uint32_t curr = 0;
   uint32_t curr_idx_l = 0, curr_idx_r = 0;
   uint64_t curr_sum = 0;

   auto do_step = [ & ]()
   {
      uint64_t tmp_l = last_result_l + abs_diff( last_idx_l, curr_idx_r ) + curr_sum;
      tmp_l = std::min( tmp_l, last_result_r + abs_diff( last_idx_r, curr_idx_r ) + curr_sum );

      uint64_t tmp_r = last_result_l + abs_diff( last_idx_l, curr_idx_l ) + curr_sum;
      tmp_r = std::min( tmp_r, last_result_r + abs_diff( last_idx_r, curr_idx_l ) + curr_sum );

      last_result_l = tmp_l;
      last_idx_l = curr_idx_l;

      last_result_r = tmp_r;
      last_idx_r = curr_idx_r;
   };

   for( uint32_t i = 0; i < N; ++i )
   {
      if( curr != data[ idx[ i ] ] )
      {
         do_step();

         curr = data[ idx[ i ] ];
         curr_idx_l = curr_idx_r = idx[ i ];
         curr_sum = 1;
      }
      else
      {
         curr_idx_r = idx[ i ];
         curr_sum += ( 1 + ( idx[ i ] - idx[ i-1 ] ) );
      }
   }
   do_step();

   std::printf( "%" PRIu64 "\n", std::min( last_result_l, last_result_r ) );

   return 0;
}

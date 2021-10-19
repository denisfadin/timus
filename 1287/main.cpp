#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>

int main()
{
   uint32_t const MAX_N = 1400;

   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< bool > map( N*N );
   for( uint32_t i = 0; i < N; ++i )
   {
      std::array< char, MAX_N+1 > buf;
      std::scanf( "%s", buf.data() );

      for( uint32_t j = 0; j < N; ++j )
         map[ i*N+j ] = ( buf[j] == 'S' );
   }

   uint32_t max_S = 0;
   uint32_t max_s = 0;

   auto do_iter = [ & ]( int32_t& sum, uint32_t i, uint32_t j )
   {
      if( map[ i*N + j ] )
      {
         if( sum >= 0 )
            sum += 1;
         else
            sum = 1;
      }
      else
      {
         if( sum <= 0 )
            sum -= 1;
         else
            sum = -1;
      }

      if( sum > 0 )
         max_S = std::max( max_S, static_cast< uint32_t >( sum ) );
      else
         max_s = std::max( max_s, static_cast< uint32_t >( -sum ) );
   };

   // horizontal
   for( uint32_t i = 0; i < N; ++i )
   {
      int32_t sum = 0;
      for( uint32_t j = 0; j < N; ++j )
         do_iter( sum, i, j );
   }

   // vertical
   for( uint32_t j = 0; j < N; ++j )
   {
      int32_t sum = 0;
      for( uint32_t i = 0; i < N; ++i )
         do_iter( sum, i, j );
   }

   // diagonal (left,top -> right,bottom)
   for( uint32_t j = 0; j < N; ++j )
   {
      int32_t sum = 0;
      for( uint32_t i = 0, k = j; k < N; ++i, ++k )
         do_iter( sum, i, k );
   }
   for( uint32_t i = 1; i < N; ++i )
   {
      int32_t sum = 0;
      for( uint32_t k = i, j = 0; k < N; ++k, ++j )
         do_iter( sum, k, j );
   }

   // diagonal (right,top -> left,bottom)
   for( uint32_t j = 0; j < N; ++j )
   {
      int32_t sum = 0;
      for( uint32_t i = j, k = 0; k <= j ; --i, ++k )
         do_iter( sum, i, k );
   }
   for( uint32_t i = 1; i < N; ++i )
   {
      int32_t sum = 0;
      for( uint32_t k = N-1, j = i; j < N; --k, ++j )
        do_iter( sum, k, j );
   }

   if( max_S > max_s )
      std::printf( "S\n%" PRIu32 "\n", max_S );
   else if( max_S < max_s )
      std::printf( "s\n%" PRIu32 "\n", max_s );
   else
      std::printf( "?\n%" PRIu32 "\n", max_S );

   return 0;
}

#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

void update( std::vector< uint32_t >& fenwick_tree,
             uint32_t N,
             int32_t x,
             int32_t y,
             int32_t z,
             int32_t diff )
{
   for( int32_t i = x; i < N; i = (i | (i+1)) )
      for( int32_t j = y; j < N; j = (j | (j+1)) )
         for( int32_t k = z; k < N; k = (k | (k+1)) )
            fenwick_tree[ (i*N+j)*N+k ] += diff;
}

uint32_t sum( std::vector< uint32_t >& fenwick_tree,
              uint32_t N,
              int32_t x,
              int32_t y,
              int32_t z )
{
   uint32_t result = 0;

   for( int32_t i = x; i >= 0; i = (i & (i+1)) - 1 )
      for( int32_t j = y; j >= 0; j = (j & (j+1)) - 1 )
         for( int32_t k = z; k >= 0; k = (k & (k+1)) - 1 )
            result += fenwick_tree[ (i*N+j)*N+k ];

   return result;
}

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< uint32_t > fenwick_tree( N*N*N, 0 );

   while( true )
   {
      uint32_t type;
      std::scanf( "%" SCNu32, &type );
      if( type == 1 ) // update
      {
         int32_t x, y, z, k;
         std::scanf( "%" SCNd32 " %" SCNd32 " %" SCNd32 " %" SCNd32, &x, &y, &z, &k );

         update( fenwick_tree, N, x, y, z, k );
      }
      else if( type == 2 ) // sum
      {
         int32_t x1, y1, z1, x2, y2, z2;
         std::scanf( "%" SCNd32 " %" SCNd32 " %" SCNd32
                     " %" SCNd32 " %" SCNd32 " %" SCNd32,
                     &x1, &y1, &z1,
                     &x2, &y2, &z2 );

         int64_t result = 0;

         result += sum( fenwick_tree, N, x2, y2, z2 );

         result -= sum( fenwick_tree, N, x1-1, y2, z2 );

         result -= sum( fenwick_tree, N, x2, y1-1, z2 );
         result += sum( fenwick_tree, N, x1-1, y1-1, z2 );

         result -= sum( fenwick_tree, N, x2, y2, z1-1 );
         result += sum( fenwick_tree, N, x2, y1-1, z1-1 );
         result += sum( fenwick_tree, N, x1-1, y2, z1-1 );
         result -= sum( fenwick_tree, N, x1-1, y1-1, z1-1 );

         std::printf( "%" PRId64 "\n", result );
      }
      else
         break;
   }

   return 0;
}

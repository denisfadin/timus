#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <limits>

struct Edge
{
   uint16_t a;
   uint16_t b;
   int16_t c;
};

int64_t FordBellman( uint16_t N, std::vector< Edge > const& edges, uint16_t S, uint16_t F )
{
   std::vector< int64_t > distance( N, std::numeric_limits<int64_t>::min() );

   distance[S] = 0;
   for( uint16_t i = 1; i < N; ++i )
   {
      for( auto const& e : edges )
      {
         if( distance[e.a] != std::numeric_limits<int64_t>::min() && distance[e.b] < distance[e.a] + e.c )
            distance[e.b] = distance[e.a] + e.c;
      }
   }

   return distance[F];
}

int main()
{
   uint16_t N;
   uint32_t M;
   scanf( "%" SCNu16 "%" SCNu32, &N, &M );

   std::vector< Edge > edges;
   edges.resize( M );

   for( uint32_t i = 0; i < M; ++i )
   {
      auto& e = edges[i];
      scanf( "%" SCNu16 "%" SCNu16 "%" SCNd16, &e.a, &e.b, &e.c );
      --e.a;
      --e.b;
   }

   uint16_t S, F;
   scanf( "%" SCNu16 "%" SCNu16, &S, &F );
   --S;
   --F;

   int64_t result = FordBellman( N, edges, S, F );
   if( result != std::numeric_limits<int64_t>::min() )
      printf( "%" PRId64 "\n", result );
   else
      printf( "No solution\n" );

   return 0;
}

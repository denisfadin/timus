#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <vector>
#include <limits>
#include <algorithm>

int main()
{
   uint32_t const N = 1000;

   auto key = [ & ]( uint32_t i, uint32_t j )
   {
      return i*(N+1)+j;
   };

   // dp[i][j] - maximum number of floors that can be checked with i eggs after j steps
   std::vector< uint32_t > DP( (N+1)*(N+1), 0 );
   for( uint32_t i = 1; i <= N; ++i )
   {
      DP[key(i, 1)] = 1;
      for( uint32_t j = 2; j <= N; ++j )
         DP[key(i, j)] = 1 + DP[key(i-1, j-1)] + DP[key(i, j-1)];
   }

   while( true )
   {
      uint32_t eggs, floors;
      std::scanf( "%" SCNu32 "%" SCNu32, &eggs, &floors );
      if( eggs == 0 && floors == 0 )
         break;

      auto b = DP.begin() + eggs*(N+1);
      auto e = b + N+1;
      auto it = std::lower_bound( b, e, floors );
      std::printf( "%" PRIu32 "\n", it - b );
   }

   return 0;
}

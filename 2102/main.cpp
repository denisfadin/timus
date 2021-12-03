#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

int main()
{
   uint64_t MAX_N = 10000000;
   std::vector< bool > buf( MAX_N+1, true );

   uint64_t N;
   std::scanf( "%" SCNu64, &N );

   uint64_t count = 0;

   for( uint64_t i = 2; i <= MAX_N; ++i )
   {
      if( !buf[ i ] )
         continue;

      while( N % i == 0 )
      {
         N /= i;
         ++count;
      }

      for( uint64_t j = i*i; j <= MAX_N; j += i )
         buf[ j ] = false;
   }

    if( N > 1 )
       ++count;

   if( count == 20 )
      std::printf( "Yes\n" );
   else
      std::printf( "No\n" );

   return 0;
}

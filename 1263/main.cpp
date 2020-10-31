#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

int main()
{
   uint32_t N, M;
   std::scanf( "%" SCNu32 "%" SCNu32, &N, &M );

   std::vector< uint16_t > candidates( N, 0 );
   for( uint32_t i = 0; i < M; ++i )
   {
      uint32_t vote;
      std::scanf( "%" SCNu32, &vote );

      candidates[ vote-1 ] += 1;
   }

   for( auto const& c : candidates )
      printf( "%.2f%%\n", static_cast< float >( c * 100 ) / M );

   return 0;
}

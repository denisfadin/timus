#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <array>
#include <vector>

uint32_t const M = 1000000009;

bool IsPrimeNumber( uint16_t num )
{
   for( uint16_t i = 2; i < num; ++i )
      if( num % i == 0 )
         return false;
   return true;
}

int main()
{
   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   std::array< uint32_t, 100 > cache, tmp_cache;

   std::vector< std::pair< uint8_t, uint8_t > > numbers;
   numbers.reserve( 143 );
   cache.fill( 0 );
   for( uint16_t i = 100; i < 1000; ++i )
   {
      if( IsPrimeNumber( i ) )
      {
         uint8_t first = i / 10;
         uint8_t second = i % 100;
         numbers.emplace_back( first, second );

         cache[ first ] += 1;
      }
   }

   for( uint16_t i = 4; i <= N; ++i )
   {
      tmp_cache.fill( 0 );

      for( auto const& num : numbers )
      {
         tmp_cache[ num.first ] += cache[ num.second ];
         tmp_cache[ num.first ] %= M;
      }

      std::swap( cache, tmp_cache );
   }

   uint32_t result = 0;
   for( uint32_t i = 0; i < 100; ++i )
   {
      result += cache[ i ];
      result %= M;
   }

   std::printf( "%" PRIu32 "\n", result );

   return 0;
}

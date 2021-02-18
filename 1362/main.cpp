#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <limits>
#include <unordered_map>
#include <algorithm>

uint32_t DP( uint32_t key, std::unordered_map< uint32_t, std::vector< uint32_t > >& kids )
{
   auto const& key_kids = kids[ key ];
   if( key_kids.empty() )
      return 0;

   uint32_t key_kids_max = 0;
   for( auto const& kid : key_kids )
      key_kids_max = std::max( key_kids_max, DP( kid, kids ) );

   uint32_t result = key_kids_max + 1;
   if( key_kids.size() > key_kids_max + 1 )
      result += key_kids.size() - key_kids_max - 1;

   return result;
}

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< uint32_t > data( N + 1, std::numeric_limits< uint32_t >::max() );

   for( uint32_t i = 1; i <= N; ++i )
   {
      while( true )
      {
         uint32_t s;
         std::scanf( "%" SCNu32, &s );
         if( s == 0 )
            break;
         data[ s ] = i;
      }
   }

   uint32_t T;
   std::scanf( "%" SCNu32, &T );

   // немного модифицируем дерево чтоб Таня стала его корнем
   {
      uint32_t tmp = data[ T ];
      data[ T ] = std::numeric_limits< uint32_t >::max();
      uint32_t tmp_root = T;
      while( tmp != std::numeric_limits< uint32_t >::max() )
      {
         uint32_t t = data[ tmp ];
         data[ tmp ] = tmp_root;
         tmp_root = tmp;
         tmp = t;
      }
   }

   std::unordered_map< uint32_t, std::vector< uint32_t > > kids;
   kids.reserve( N );

   for( uint32_t i = 1; i <= N; ++i )
   {
      if( data[ i ] == std::numeric_limits< uint32_t >::max() )
         continue;
      kids[ data[ i ] ].push_back( i );
   }

   std::printf( "%" PRIu32 "\n", DP( T, kids ) );

   return 0;
}

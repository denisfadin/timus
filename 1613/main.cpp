#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
   uint32_t N;
   scanf( "%" SCNu32, &N );

   using BufValueT = std::pair< uint32_t, uint32_t >;

   std::vector< BufValueT > buf;
   buf.resize( N );

   for( uint32_t i = 0; i < N; ++i )
   {
      auto& p = buf[i];
      scanf( "%" SCNu32, &p.first );
      p.second = i+1;
   }

   auto cmp = []( BufValueT const& a, BufValueT const& b ) -> bool
   {
      if( a.first == b.first )
         return a.second < b.second;
      return a.first < b.first;
   };

   std::sort( buf.begin(), buf.end(), cmp );

   uint32_t Q;
   scanf( "%" SCNu32, &Q );

   for( uint32_t i = 0; i < Q; ++i )
   {
      uint32_t l, r, x;
      scanf( "%" SCNu32 " %" SCNu32 " %" SCNu32, &l, &r, &x );

      bool finded = false;

      auto it = std::lower_bound( buf.begin(), buf.end(), std::make_pair( x, l ), cmp );

      if( it != buf.end() )
      {
         if( it->first == x && it->second <= r )
            finded = true;
      }

      printf( finded ? "1" : "0" );
   }

   printf( "\n" );

   return 0;
}

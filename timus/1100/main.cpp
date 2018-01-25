#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   uint32_t n;
   scanf( "%" SCNu32, &n );

   using ElemType = std::pair<uint32_t,uint16_t>;

   std::vector< ElemType > buf;
   buf.resize( n );
   for( auto& e : buf )
      scanf( "%" SCNu32 "%" SCNu16, &e.first, &e.second );

   std::stable_sort( std::begin( buf ), std::end( buf ), []( ElemType const& a, ElemType const& b ) -> bool
   {
      return a.second > b.second;
   });

   for( auto const& e : buf )
      printf( "%" PRIu32 " %" PRIu16 "\n", e.first, e.second );

   return 0;
}

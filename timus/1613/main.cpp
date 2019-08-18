#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <unordered_map>

int main()
{
   uint32_t N;
   scanf( "%" SCNu32, &N );

   std::unordered_multimap< uint32_t, uint32_t > buf;
   for(uint32_t i = 1; i <= N; ++i )
   {
      uint32_t num;
      scanf( "%" SCNu32, &num );
      buf.insert( std::make_pair( std::move(num), i ) );
   }

   uint32_t Q;
   scanf( "%" SCNu32, &Q );

   for( uint32_t i = 0; i < Q; ++i )
   {
      uint32_t l, r, x;
      scanf( "%" SCNu32 " %" SCNu32 " %" SCNu32, &l, &r, &x );

      bool finded = false;
      auto range = buf.equal_range( x );
      for( auto it = range.first; it != range.second; ++it )
      {
         if( it->second >= l && it->second <= r )
         {
            finded = true;
            break;
         }
      }

      printf( finded ? "1" : "0" );
   }

   printf( "\n" );

   return 0;
}

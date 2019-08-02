#include <cinttypes>
#include <cstdio>
#include <vector>

uint32_t median( std::vector< uint32_t >& arr )
{
   auto idx = arr.size() / 2; // с таким номером элемент нам требуется найти
   auto beg = arr.begin();
   auto end = arr.end();
   while( true )
   {
      auto cur = beg;
      for( auto it = beg + 1; it != end; ++it )
      {
         if( *cur >= *it )
         {
            auto tmp = *it;
            *it = *(cur+1);
            *(cur+1) = *cur;
            *cur = tmp;
            ++cur;
         }
      }

      auto d = std::distance( beg, cur );
      if( d == idx )
         return *cur;
      else if( d > idx )
      {
         end = cur;
      }
      else
      {
         beg = cur + 1;
         idx -= d;
      }
   }
}

int main()
{
   uint32_t N;
   scanf( "%" SCNu32, &N );

   std::vector< uint32_t > arr;
   arr.resize( N );
   for( auto const& e : arr )
      scanf( "%" SCNu32, &e );

   printf( "%" PRIu32 "\n", median( arr ) );

   return 0;
}

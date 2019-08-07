#include <cinttypes>
#include <cstdio>
#include <vector>

float median( std::vector< uint32_t >& arr )
{
   float result = 0;

   auto idx = arr.size() / 2; // с таким номером элемент нам требуется найти
   auto beg = arr.begin();
   auto end = arr.end();

   for( uint32_t i = 0; i < 2; ++i )
   {
      if( i && arr.size() % 2 )
         break;

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
         {
            result += *cur;
            if( i )
            {
               result /= 2;
            }
            else
            {
               beg = arr.begin();
               end = cur;
               idx = std::distance( beg, end ) - 1;
            }
            break;
         }
         else if( d > idx )
         {
            end = cur;
         }
         else
         {
            beg = cur + 1;
            idx -= d + 1;
         }
      }
   }

   return result;
}

int main()
{
   uint32_t N;
   scanf( "%" SCNu32, &N );

   std::vector< uint32_t > arr;
   arr.resize( N );
   for( auto const& e : arr )
      scanf( "%" SCNu32, &e );

   printf( "%.1f\n", median( arr ) );

   return 0;
}

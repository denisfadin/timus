#include <cinttypes>
#include <cstdio>
#include <vector>

float median( std::vector< uint32_t >& arr )
{
   float result = 0;

   auto idx = arr.size() / 2; // с таким номером элемент нам требуется найти
   uint32_t beg = 0;
   uint32_t end = arr.size();

   for( uint32_t times = 0; times < 2; ++times )
   {
      if( times && arr.size() % 2 )
         break;

      while( true )
      {
         auto cur = beg;
         for( auto i = beg + 1; i < end; ++i )
         {
            auto cur_value = arr[cur];
            auto i_value = arr[i];
            if( cur_value >= i_value )
            {
               auto tmp = i_value;
               arr[i] = arr[cur+1];
               arr[cur+1] = cur_value;
               arr[cur] = tmp;
               ++cur;
            }
         }

         auto d = cur - beg;
         if( d == idx )
         {
            result += arr[cur];
            if( times )
            {
               result /= 2;
            }
            else
            {
               beg = 0;
               end = cur;
               idx = end - 1;
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

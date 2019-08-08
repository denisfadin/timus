#include <cinttypes>
#include <cstdio>
#include <queue>
#include <deque>

int main()
{
   uint32_t N;
   scanf( "%" SCNu32, &N );

   std::priority_queue< uint32_t, std::deque< uint32_t > > queue;
   uint32_t const max_queue_size = N / 2 + 1;

   for( uint32_t i = 0; i < N; ++i )
   {
      uint32_t e;
      scanf( "%" SCNu32, &e );
      if( queue.size() < max_queue_size )
      {
         queue.push( std::move(e) );
      }
      else
      {
         if( queue.top() > e )
         {
            queue.pop();
            queue.push( std::move(e) );
         }
      }
   }

   double result = queue.top();
   if( N % 2 == 0)
   {
      queue.pop();
      result += queue.top();
      result /= 2;
   }

   printf( "%.1f\n", result );

   return 0;
}

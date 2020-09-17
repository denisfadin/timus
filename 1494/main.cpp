#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <stack>

int main()
{
   uint32_t N;
   scanf( "%" SCNu32, &N );

   std::stack< uint32_t > stack;
   uint32_t max = 1;
   stack.push( max );
   for( uint32_t i = 0; i < N; ++i )
   {
      uint32_t num;
      scanf( "%" SCNu32, &num );

      if( num > max )
      {
         for( uint32_t j = max + 1; j <= num; ++j )
            stack.push( j );
         max = num;
      }
      else if( stack.top() != num )
         break;

      stack.pop();
   }

   if( stack.empty() )
      printf( "Not a proof\n" );
   else
      printf( "Cheater\n" );

   return 0;
}

#include <cstdint>
#include <iostream>
#include <deque>

int main()
{
   int32_t M;
   std::cin >> M;

   struct Value
   {
      int32_t idx;
      int32_t value;
   };

   std::deque< Value > stack;

   auto push_next = [ &stack ]( Value&& v )
   {
      while( !stack.empty() )
      {
         if( stack.back().value >= v.value )
            break;
         stack.pop_back();
      }
      stack.push_back( std::move(v) );
   };

   uint32_t i = 0;
   for( ; i < M; ++i )
   {
      Value v;
      v.idx = i;
      std::cin >> v.value;

      push_next( std::move( v ) );
   }

   while( true )
   {
      std::cout << stack.front().value << std::endl;
      if( stack.front().idx == i-M )
         stack.pop_front();

      Value v;
      v.idx = i++;
      std::cin >> v.value;
      if( v.value == -1 )
         break;

      push_next( std::move(v) );
   }

   return 0;
}

#include <cstdio>
#include <cinttypes>
#include <cstdint>
#include <deque>
#include <stack>

int main()
{
   uint32_t N;
   scanf( "%" SCNu32, &N );

   struct Segment
   {
      uint32_t a;
      uint32_t b;
   };

   std::deque< Segment > segments;
   for( uint32_t i = 0; i < N; ++i )
   {
      Segment s;
      scanf( "%" SCNu32 " %" SCNu32, &s.a, &s.b );
      segments.push_back( std::move( s ) );
   }

   std::stack< std::pair< Segment, uint32_t > > stack;
   uint32_t segment_num = 0;

   uint32_t M;
   scanf( "%" SCNu32, &M );
   for( uint32_t i = 0; i < M; ++i )
   {
      uint32_t c;
      scanf( "%" SCNu32, &c );

      while( !stack.empty() )
      {
         auto const& t = stack.top();
         if( c <= t.first.b )
            break;
         stack.pop();
      }

      while( !segments.empty() )
      {
         auto const& f = segments.front();
         if( c < f.a )
            break;
         else if( c <= f.b )
         {
            stack.push( std::make_pair( std::move( segments.front() ), ++segment_num ) );
            segments.pop_front();
         }
         else
         {
            ++segment_num;
            segments.pop_front();
         }
      }

      if( !stack.empty() && c >= stack.top().first.a && c <= stack.top().first.b )
         printf( "%" PRIu32 "\n", stack.top().second );
      else
         printf( "-1\n" );
   }

   return 0;
}

#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< int32_t > stack;
   stack.reserve( N );

   for( uint32_t i = 0; i < N; ++i )
   {
      int32_t command;
      std::scanf( "%" SCNd32, &command );

      if( command > 0 )
         stack.push_back( std::move( command ) );
      else if( command == 0 )
      {
         if( !stack.empty() )
            stack.push_back( -stack.size()+1 );
      }
      else // -1
      {
         while( true )
         {
            auto& back = stack.back();
            if( back > 0 )
            {
               std::printf( "%" PRId32 "\n", stack.back() );
               stack.pop_back();
               break;
            }
            else
            {
               auto pos = -back;

               if( ++back > 0 )
                  stack.pop_back();

               auto val = stack[ pos ];
               if( val > 0 )
               {
                  std::printf( "%" PRId32 "\n", val );
                  break;
               }

               stack.push_back( std::move( val ) );
            }
         }
      }
   }

   return 0;
}

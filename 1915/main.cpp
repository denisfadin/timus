#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

int main()
{
   uint_fast32_t N;
   std::scanf( "%" SCNuFAST32, &N );

   std::vector< int_fast32_t > stack;
   stack.reserve( N );

   for( uint_fast32_t i = 0; i < N; ++i )
   {
      int_fast32_t command;
      std::scanf( "%" SCNdFAST32, &command );

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
               std::printf( "%" PRIdFAST32 "\n", stack.back() );
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
                  std::printf( "%" PRIdFAST32 "\n", val );
                  break;
               }

               stack.push_back( std::move( val ) );
            }
         }
      }
   }

   return 0;
}

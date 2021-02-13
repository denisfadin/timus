#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <array>
#include <cctype>
#include <algorithm>

int main()
{
   std::array< uint32_t, 4 > dp;
   dp.fill(0);

   while( true )
   {
      auto sym = std::getchar();
      if( std::isalpha( sym ) )
      {
         ++dp[ 3 ];
         continue;
      }

      if( dp[ 3 ] > 0 )
      {
         dp[ 3 ] += std::max( dp[ 0 ], dp[ 1 ] );

         dp[ 0 ] = dp[ 1 ];
         dp[ 1 ] = dp[ 2 ];
         dp[ 2 ] = dp[ 3 ];
         dp[ 3 ] = 0;
      }

      if( sym == EOF )
         break;
   }

   std::printf( "%" PRIu32 "\n", std::max( dp[ 1 ], dp[ 2 ] ) );

   return 0;
}

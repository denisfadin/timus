#include <iostream>
#include <stdint.h>
#include <vector>
#include <set>

int main()
{
   int16_t N, M;
   std::cin >> N >> M;

   char sym;
   std::cin >> sym;

   std::vector< char > buf;
   buf.resize( N*M );

   for( int16_t i = 0; i < N*M; ++i )
      std::cin >> buf[ i ];

   std::set< char > res;

   //std::cout << std::endl;

   auto process = [&buf, &res, sym]( int i ) -> void
   {
      char c = buf[i];
      if( c != '.' && c != sym )
      {
         //std::cout << " -> " << i << ' ' << c << std::endl;
         res.insert( c );
      }
   };

   for( int16_t i = 0; i < N*M; ++i )
   {
      if( buf[i] == sym )
      {
         //std::cout << i << std::endl;
         if( (i+1)%M )
            process( i+1 );

         if( i%M )
            process( i-1 );

         if( (i-M) >= 0 )
            process( i-M );

         if( (i+M) < buf.size() )
            process( i+M );
      }
   }

   std::cout << res.size() << std::endl;

   return 0;
}

#include <iostream>
#include <cstdint>
#include <vector>

int main()
{
   std::vector< uint32_t > requests;
   uint32_t max_request = 0;
   while( true )
   {
      uint32_t r;
      std::cin >> r;
      if( r == 0 )
         break;
      max_request = std::max( max_request, r );
      requests.emplace_back( std::move(r) );
   }

   std::vector< uint32_t > buf;
   buf.resize( max_request+1 );

   std::vector< uint32_t > buf_max;
   buf_max.resize( max_request+1 );

   buf[0] = buf_max[0] = 0;
   buf[1] = buf_max[1] = 1;

   for( uint32_t i = 2; i <= max_request; ++i )
   {
      if( i%2 == 0 )
         buf[i] = buf[i>>1];
      else
         buf[i] = buf[i>>1] + buf[(i>>1)+1];

      buf_max[i] = std::max( buf_max[i-1], buf[i] );
   }

   for( uint32_t i = 0; i < requests.size(); ++i )
      std::cout << buf_max[ requests[i] ] << std::endl;

   return 0;
}

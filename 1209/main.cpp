#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
   std::vector< uint32_t > one_poses;
   one_poses.push_back( 1 );
   for( uint32_t i = 1; ; ++i )
   {
      auto pos = static_cast< uint64_t >( one_poses.back() ) + i;
      if( pos > std::numeric_limits< uint32_t >::max() )
         break;
      one_poses.push_back( static_cast< uint32_t >( pos ) );
   }

   uint32_t N;
   std::cin >> N;

   for( uint32_t i = 0; i < N; ++i )
   {
      uint32_t pos;
      std::cin >> pos;
      auto it = std::lower_bound( one_poses.begin(), one_poses.end(), pos );
      if( it != one_poses.end() && *it == pos )
         std::cout << "1 ";
      else
         std::cout << "0 ";
   }
   return 0;
}

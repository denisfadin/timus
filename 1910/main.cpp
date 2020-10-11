#include <iostream>
#include <cstdint>

int main()
{
   uint32_t N;
   std::cin >> N;
   
   uint32_t e1, e2, e3;
   std::cin >> e1 >> e2 >> e3;

   uint32_t max = e1 + e2 + e3;
   uint32_t max_pos = 1;

   for( uint32_t i = 3; i < N; ++i )
   {
      std::swap( e1, e2 );
      std::swap( e2, e3 );
      std::cin >> e3;
      
      uint32_t max_tmp = e1 + e2 + e3;
      if( max_tmp > max )
      {
         max = max_tmp;
         max_pos = i-1;
      }
   }
   
   std::cout << max << " " << max_pos + 1 << std::endl;
   
   return 0;
}

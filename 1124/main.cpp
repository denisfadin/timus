#include <cstdint>
#include <vector>
#include <deque>
#include <iostream>

int main()
{
   uint32_t m, n;
   std::cin >> m >> n;

   std::vector< uint32_t > buf(m*m, 0);
   
   for( uint32_t i = 0; i < m; ++i )
      for( uint32_t j = 0; j < n; ++j )
      {
         uint32_t a;
         std::cin >> a;
         --a;
         if(a != i)
         {
            ++buf[i*m+a];
         }
      }

   uint32_t result = 0;

   std::vector< bool > marked(m, false);
   for( uint32_t i = 0; i < m; ++i )
   {
      std::deque< uint32_t > list;
      list.push_back(i);

      uint32_t res = 0;
      while( !list.empty() )
      {
         uint32_t e = list.front();
         list.pop_front();
         if( marked[e] )
            continue;
           
         marked[ e ] = true;

         for( uint32_t j = 0; j < m; ++j )
         {
            uint32_t c = buf[e*m+j];
            if( c )
            {
               res += c;
               list.push_back(j);
            }
         }
      }

      if( res )
      {
         if( result )
            ++result;
         result += res;
      } 
   }
   
   std::cout << result << std::endl;

   return 0;
}

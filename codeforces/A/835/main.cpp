#include <iostream>
#include <stdint.h>

int main()
{
   int16_t s, v1, v2, t1, t2;
   std::cin >> s >> v1 >> v2 >> t1 >> t2;

   int32_t res1 = t1 + s*v1 + t1;
   int32_t res2 = t2 + s*v2 + t2;

   if( res1 == res2 )
      std::cout << "Friendship";
   else if( res1 < res2 )
      std::cout << "First";
   else
      std::cout << "Second";

   std::cout << std::endl;

   return 0;
}

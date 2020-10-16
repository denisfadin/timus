#include <cstdint>
#include <iostream>

int main()
{
   uint32_t N;
   std::cin >> N;

   uint32_t result;
   if( N == 1 )
      result = 1;
   else if( N % 4 == 0 )
      result = 0;
   else if( N % 4 == 3 || ( N % 4 == 1 && N % 5 == 0 ) )
      result = 2;
   else
      result = 1;

   std::cout << result << std::endl;

   return 0;
}

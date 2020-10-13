#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
   std::srand(std::time(nullptr));
   for( uint32_t i = 0; i < 1000000; ++i )
      printf( "%c", 'a' + std::rand() % 26 );

   return 0;
}

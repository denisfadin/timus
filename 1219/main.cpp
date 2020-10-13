#include <cstdint>
#include <cstdio>
#include <cstdlib>

int main()
{
   std::srand(42);
   for( uint32_t i = 0; i < 1000000; ++i )
      printf( "%c", 'a' + std::rand() % 26 );

   return 0;
}

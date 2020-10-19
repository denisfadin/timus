#include <cstdint>
#include <iostream>
#include <unordered_map>

class StairsCalculator
{
public:

   uint64_t Do( uint32_t cubes );

private:

   std::unordered_map< uint32_t, uint64_t > mCache;

   static uint32_t CacheKey( uint32_t a, uint32_t b ) noexcept
   {
      return (a << 16) + b;
   }

   uint64_t DoImpl( uint32_t cubes, uint32_t last_step_height );

};

uint64_t StairsCalculator::DoImpl( uint32_t cubes, uint32_t last_step_height )
{
   if( cubes < last_step_height )
      return 0;
   else if( cubes == last_step_height )
      return 1;

   auto cache_key = CacheKey( cubes, last_step_height );
   auto it = mCache.find( cache_key );
   if( it != mCache.end() )
      return it->second;

   uint64_t result = 0;
   for( uint32_t i = 1; i < last_step_height; ++i )
      result += DoImpl( cubes - last_step_height, i );

   mCache[ cache_key ] = result;

   return result;
}

uint64_t StairsCalculator::Do( uint32_t cubes )
{
   uint64_t result = 0;

   for( uint32_t i = 3; i < cubes; ++i )
      result += DoImpl( cubes, i );

   return result;
}

int main()
{
   uint32_t N;
   std::cin >> N;

   std::cout << StairsCalculator{}.Do( N ) << std::endl;

   return 0;
}

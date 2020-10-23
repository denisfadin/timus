#include <cstdint>
#include <iostream>
#include <unordered_map>

class Calculator
{
public:

   uint64_t Do( uint32_t sum, uint32_t length )
   {
      if( length == 1 )
      {
         if( sum >= 0 && sum <= 9 )
            return 1;
         return 0;
      }

      uint32_t cache_key = ( sum << 16 ) + length;

      auto it = mCache.find( cache_key );
      if( it != mCache.end() )
         return it->second;

      uint64_t result = 0;

      for( uint32_t i = 0; i <= 9; ++i )
      {
         if( sum < i )
            continue;

         result += Do( sum - i, length - 1 );
      }

      mCache[ cache_key ] = result;

      return result;
   }
private:

   std::unordered_map< uint32_t, uint64_t > mCache;
};

int main()
{
   uint32_t N, S;
   std::cin >> N >> S;

   uint64_t result = 0;
   if( S % 2 == 0 )
      result = Calculator{}.Do( S >> 1, N );

   std::cout << ( result * result ) << std::endl;

   return 0;
}

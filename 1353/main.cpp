#include <cstdint>
#include <iostream>
#include <unordered_map>

uint32_t const MAX_LENGTH = 10;

class Calculator
{
public:

   uint32_t Do( uint32_t sum, uint32_t length )
   {
      uint32_t const cache_key = ( sum << 16 ) + length;

      auto it = mCache.find( cache_key );
      if( it != mCache.end() )
         return it->second;

      uint32_t result = 0;
      if( length == 1 )
      {
         if( sum >= 0 && sum <= 9 )
            result = 1;
      }
      else
      {
         for( uint32_t j = 1; j <= 9; ++j )
         {
            if( sum >= j )
            {
               for( uint32_t l = length - 1; l > 0; --l )
                  result += Do( sum - j, l );
            }
         }
      }

      mCache[ cache_key ] = result;

      return result;
   }

private:

   std::unordered_map< uint32_t, uint32_t > mCache;
};

int main()
{
   uint32_t S;
   std::cin >> S;

   uint32_t result = 0;

   Calculator calc;
   for( uint32_t length = MAX_LENGTH - 1; length > 0; --length )
      result += calc.Do( S, length );

   if( S == 1 )
      ++result;

   std::cout << result << std::endl;

   return 0;
}

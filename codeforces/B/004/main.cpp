#include <iostream>
#include <stdint.h>
#include <vector>

int main()
{
   int16_t d, sumTime;
   std::cin >> d >> sumTime;
   std::vector< std::pair< int16_t, int16_t > > dayLimits;
   int16_t minSumTime = 0;
   int16_t maxSumTime = 0;
   for( int16_t i = 0; i < d; ++i )
   {
      int16_t min, max;
      std::cin >> min >> max;
      minSumTime += min;
      maxSumTime += max;
      dayLimits.emplace_back( std::make_pair( min, max ) );
   }

   if( minSumTime <= sumTime && sumTime <= maxSumTime )
   {
      std::cout << "YES" << std::endl;

      int16_t addTime = sumTime - minSumTime; // дополнительное время к распределению
      for( auto const& p : dayLimits )
      {
         int16_t dayTime = p.first;
         if( addTime > 0 )
         {
            int16_t addDayTime = std::min( static_cast< int32_t >( addTime ), p.second - p.first );
            dayTime += addDayTime;
            addTime -= addDayTime;
         }
         std::cout << dayTime << " ";
      }
   }
   else
      std::cout << "NO" << std::endl;

   return 0;
}

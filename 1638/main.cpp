#include <cstdint>
#include <iostream>

int main()
{
   uint32_t volume_thickness, binding_thickness, start, finish;
   std::cin >> volume_thickness >> binding_thickness >> start >> finish;

   uint32_t result = 0;
   if( finish > start )
      result = (finish - start - 1) * volume_thickness + (finish - start) * binding_thickness * 2;
   else
      result = (start - finish + 1) * volume_thickness + (start - finish) * binding_thickness * 2;

   std::cout << result << std::endl;

   return 0;
}

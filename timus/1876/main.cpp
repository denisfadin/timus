#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <algorithm>

uint32_t const LEGS_NUMBER = 40;

int main()
{
   uint32_t a, b;
   scanf( "%" SCNu32 "%" SCNu32, &a, &b );

   // одел сначала все правые, затем откинул все оставшиеся правые и далее уже одел левые
   auto v1 = 2*LEGS_NUMBER + 2*(b-LEGS_NUMBER) + LEGS_NUMBER;

   // одел все без одной правые, затем одел все левые, потом откинул все оставшиеся левые и одел последнюю правую
   auto v2 = 2*(LEGS_NUMBER-1) + LEGS_NUMBER + 2*(a-LEGS_NUMBER) + 1;

   printf( "%" PRIu32 "\n", std::max( v1, v2 ) );
}

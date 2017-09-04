#include <iostream>
#include <stdint.h>
#include <cmath>

int main()
{
   int64_t ax, ay, bx, by, cx, cy;
   std::cin >> ax >> ay >> bx >> by >> cx >> cy;

   auto ab = std::sqrt( (bx-ax)*(bx-ax) + (by-ay)*(by-ay) );
   auto bc = std::sqrt( (cx-bx)*(cx-bx) + (cy-by)*(cy-by) );
   auto ca = std::sqrt( (cx-ax)*(cx-ax) + (cy-ay)*(cy-ay) );

   // точки не лежат на прямой и расстояния равны
   if( !(ab+bc==ca || bc+ca==ab || ca+ab==bc) && ab == bc )
      std::cout << "Yes";
   else
      std::cout << "No";

   std::cout << std::endl;

   return 0;
}

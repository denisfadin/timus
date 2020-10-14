#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
   float D, R;
   std::cin >> D >> R;

   float const PI = 3.14159265;
   float result;
   if( R <= D / 2 )
   {
      // площадь круга
      result = PI*R*R;
   }
   else if( R >= sqrt(2)*D/2 )
   {
      // площать квадрата
      result = D*D;
   }
   else
   {
      // вычисляем площать сегмента, выходящего за рамки огорода
      // всего таких 4шт, их нужно будет вычесть из общей площади круга
      float h = R - D / 2;
      float l = 2 * acos( 1 - h / R);
      float s = R*R*(l - sin(l))/2;
      result = PI*R*R - 4*s;
   }

   std::cout << std::fixed << std::setprecision(3) << result << std::endl;

   return 0;
}

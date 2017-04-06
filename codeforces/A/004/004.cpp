// http://codeforces.com/problemset/problem/4/A

#include <iostream>

int main()
{
    int w;
    std::cin >> w;
    std::cout << ( ( w < 4 || w % 2 ) ? "NO" : "YES" ) << std::endl;
    return 0;
}

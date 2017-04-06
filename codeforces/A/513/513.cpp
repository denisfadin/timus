// http://codeforces.com/problemset/problem/513/A

#include <iostream>

int main()
{
    int n1, n2, k1, k2;
    std::cin >> n1 >> n2 >> k1 >> k2;
    std::cout << ( n1 > n2 ? "First" : "Second" ) << std::endl;
    return 0;
}

// http://codeforces.com/problemset/problem/1/A

#include <iostream>

int main()
{
    long long n, m, a;
    std::cin >> n >> m >> a;
    std::cout << ( (n+a-1)/a ) * ( (m+a-1)/a ) << std::endl;
    return 0;
}

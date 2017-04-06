// http://codeforces.com/problemset/problem/158/A

#include <iostream>

int main()
{
    int k_num = 0, cnt = 0;

    int n, k;
    std::cin >> n >> k;
    for( int i = 1; i <= n; ++i )
    {
        int x;
        std::cin >> x;

        if( !x )
            continue;

        if( i < k )
            ++cnt;
        else if( i == k )
        {
            k_num = x;
            ++cnt;
        }
        else if( x == k_num )
            ++cnt;
    }

    std::cout << cnt << std::endl;

    return 0;
}

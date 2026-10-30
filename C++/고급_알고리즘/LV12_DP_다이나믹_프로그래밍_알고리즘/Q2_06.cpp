#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[100] = {};

int main()
{
    int N;
    std::cin >> N;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    std::cout << dp[N];

    return 0;
}

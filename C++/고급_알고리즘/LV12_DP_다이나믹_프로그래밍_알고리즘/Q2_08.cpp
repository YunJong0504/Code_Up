#include <iostream>
#include <algorithm>
using namespace std;

int arr[12];
int dp[12];

int main()
{
    for (int i = 0; i < 12; i++)
    {
        std::cin >> arr[i];
        dp[i] = -1000000000;
    }

    dp[0] = 0;

    int answer = -1000000000;

    for (int i = 0; i < 12; i++)
    {
        if (dp[i] == -1000000000)
            continue;

        int next[3] = { i + 2, i + 3, i * 2 };

        for (int j = 0; j < 3; j++)
        {
            int nx = next[j];

            if (nx <= i)
                continue;

            if (nx >= 12)
            {
                answer = max(answer, dp[i]);
                continue;
            }

            dp[nx] = max(dp[nx], dp[i] + arr[nx]);
        }
    }

    std::cout << answer;

    return 0;
}

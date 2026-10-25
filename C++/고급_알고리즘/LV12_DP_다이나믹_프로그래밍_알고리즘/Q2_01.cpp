#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[4];
int dp[16];

int main()
{
    for (int i = 0; i < 4; i++)
    {
        std::cin >> arr[i];
    }

    // DP 초기화
    for (int i = 0; i < 16; i++)
    {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for (int mask = 0; mask < 16; mask++)
    {
        if (dp[mask] == INT_MAX)
            continue;

        int sum = 0;

        // 이미 화장실을 사용한 사람들의 시간 합
        for (int i = 0; i < 4; i++)
        {
            if (mask & (1 << i))
            {
                sum += arr[i];
            }
        }

        // 다음에 화장실을 사용할 사람 선택
        for (int i = 0; i < 4; i++)
        {
            if (mask & (1 << i))
                continue;

            int next = mask | (1 << i);

            dp[next] = min(dp[next], dp[mask] + sum);
        }
    }

    std::cout << dp[15];

    return 0;
}

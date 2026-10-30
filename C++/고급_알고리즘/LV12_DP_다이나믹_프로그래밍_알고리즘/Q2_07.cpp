#include <iostream>
#include <algorithm>
using namespace std;

int map[7][3];
int dp[7][3];

int main()
{
    // 입력
    for (int y = 0; y < 7; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            cin >> map[y][x];
            dp[y][x] = -1000000000;
        }
    }

    // 시작점
    dp[0][0] = map[0][0];

    // DP 계산
    for (int y = 1; y < 7; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            for (int k = -1; k <= 1; k++)
            {
                int nx = x + k;

                if (nx < 0 || nx >= 3)
                    continue;

                if (dp[y - 1][nx] == -1000000000)
                    continue;

                dp[y][x] = max(
                    dp[y][x],
                    dp[y - 1][nx] + map[y][x]
                );
            }
        }
    }

    // 최댓값 찾기
    int answer = INT_MIN;

    for (int x = 0; x < 3; x++)
    {
        answer = max(answer, dp[6][x]);
    }

    cout << answer;

    return 0;
}

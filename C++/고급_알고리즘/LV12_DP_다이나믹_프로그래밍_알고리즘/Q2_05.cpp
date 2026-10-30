#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int map[4][4];
    int dp[4][4];
    pair<int, int> parent[4][4];

    // 입력
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            cin >> map[y][x];
        }
    }

    // 시작점 초기화
    dp[0][0] = map[0][0];

    // 첫 번째 열
    for (int y = 1; y < 4; y++)
    {
        dp[y][0] = dp[y - 1][0] + map[y][0];
        parent[y][0] = { y - 1, 0 };
    }

    // 첫 번째 행
    for (int x = 1; x < 4; x++)
    {
        dp[0][x] = dp[0][x - 1] + map[0][x];
        parent[0][x] = { 0, x - 1 };
    }

    // DP 계산
    for (int y = 1; y < 4; y++)
    {
        for (int x = 1; x < 4; x++)
        {
            if (dp[y - 1][x] < dp[y][x - 1])
            {
                dp[y][x] = dp[y - 1][x] + map[y][x];
                parent[y][x] = { y - 1, x };
            }
            else
            {
                dp[y][x] = dp[y][x - 1] + map[y][x];
                parent[y][x] = { y, x - 1 };
            }
        }
    }

    // 경로 역추적
    vector<pair<int, int>> path;

    int y = 3;
    int x = 3;

    while (true)
    {
        path.push_back({ y, x });

        if (y == 0 && x == 0)
            break;

        pair<int, int> p = parent[y][x];
        y = p.first;
        x = p.second;
    }

    // 출력
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i].first << "," << path[i].second << std::endl;
    }

    return 0;
}

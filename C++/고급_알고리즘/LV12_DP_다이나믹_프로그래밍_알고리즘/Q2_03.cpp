#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    std::cin >> N;

    vector<pair<int, int>> arr(N);
    vector<int> dp(N, 1);

    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b)
        {
            if (a.second == b.second)
                return a.first < b.first;

            return a.second < b.second;
        });

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j].second <= arr[i].first)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        answer = max(answer, dp[i]);
    }

    std::cout << answer;


    return 0;
}

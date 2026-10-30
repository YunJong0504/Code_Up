#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[16][16] = {};

int main()
{
    string a, b;
    std::cin >> a >> b;

    int maxLen = 0;
    int endIndex = 0;

    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if (dp[i][j] > maxLen)
                {
                    maxLen = dp[i][j];
                    endIndex = i;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    std::cout << a.substr(endIndex - maxLen, maxLen);

    return 0;
}

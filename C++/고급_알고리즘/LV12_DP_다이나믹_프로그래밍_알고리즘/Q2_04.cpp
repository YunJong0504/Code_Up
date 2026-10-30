#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    std::cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        if (sum + arr[i] <= 100)
        {
            sum += arr[i];
            cnt++;
        }
        else
        {
            break;
        }
    }

    std::cout << cnt;
    
    return 0;
}

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void BubbleSort(std::vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    std::vector<int> arr = { 22,50,17,25,18,32,33,44,29,8 };

    BubbleSort(arr);

    return 0;
}

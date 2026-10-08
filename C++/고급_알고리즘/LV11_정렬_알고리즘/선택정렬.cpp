#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void SelectSort(std::vector<int>& arr)
{
    int n = arr.size();

    for(int j = 0; j < n - 1; j++)
    {
        int minIdx = j;
        for (int i = j + 1; i < n; i++)
        {
            if (arr[minIdx] > arr[i])
                minIdx = i;
        }
        if (minIdx != j)
            std::swap(arr[j], arr[minIdx]);
    }
}

int main()
{
    std::vector<int> arr = { 22,50,17,25,18,32,33,44,29,8 };

    SelectSort(arr);

    return 0;
}

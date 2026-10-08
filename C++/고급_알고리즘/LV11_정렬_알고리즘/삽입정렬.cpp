#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void InsertSort(std::vector<int>& arr)
{
    int n = arr.size();

    for(int j = 1; j < n; j++)
    {
        int temp = arr[j];
        for (int i = j - 1; i >= 0; i--)
        {
            if (arr[i] > temp)
            {
                arr[i + 1] = arr[i];
                if (i == 0)
                    arr[i] = temp;
            }
            else if (arr[i] <= temp)
            {
                arr[i + 1] = temp;
                break;
            }
        }
    }
}

int main()
{
    std::vector<int> arr = { 22,50,17,25,18,32,33,44,29,8 };

    InsertSort(arr);

    return 0;
}

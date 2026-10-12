#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void HeapSort(std::vector<int>& arr)
{
    std::priority_queue<int> q;
    for (int i = 0; i < arr.size(); i++)
    {
        q.push(arr[i]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = q.top();
        q.pop();
    }
}

int main()
{
    std::vector<int> arr = { 6,5,3,1,8,7,2,4 };
    HeapSort(arr);

    return 0;
}

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int vect[5] = { 6,1,3,8,5 };
int result[5] = {};

void MergeSort(int start, int end)
{
    int mid = (start + end) / 2;

    if (start == end)
        return;

    MergeSort(start, mid);
    MergeSort(mid + 1, end);

    int a = start;
    int b = mid + 1;

    int idx = 0;

    while (true)
    {
        if (a > mid && b > end)
            break;

        if (a > mid)
            result[idx++] = vect[b++];
        else if (b > end)
            result[idx++] = vect[a++];
        else if (vect[a] < vect[b])
            result[idx++] = vect[a++];
        else
            result[idx++] = vect[b++];
    }

    for (int i = 0; i < idx; i++)
    {
        vect[start + i] = result[i];
    }
}

int main()
{
    MergeSort(0, 4);

    return 0;
}

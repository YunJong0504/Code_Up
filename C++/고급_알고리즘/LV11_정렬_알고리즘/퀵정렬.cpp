#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int>& arr)
{
    auto sort = [&](auto&& self, int left, int right) -> void
        {
            if (left >= right)
                return;

            int pivot = arr[(left + right) / 2];
            int i = left;
            int j = right;

            while (i <= j)
            {
                while (arr[i] < pivot)
                    i++;

                while (arr[j] > pivot)
                    j--;

                if (i <= j)
                {
                    swap(arr[i], arr[j]);
                    i++;
                    j--;
                }
            }

            if (left < j)
                self(self, left, j);

            if (i < right)
                self(self, i, right);
        };

    if (!arr.empty())
        sort(sort, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = { 5, 3, 1, 4, 2 };

    QuickSort(arr);

    return 0;
}

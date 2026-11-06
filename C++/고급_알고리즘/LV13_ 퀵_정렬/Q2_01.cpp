#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[10];
    int dat[21] = {};
    int result[10] = {};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dat[arr[i]]++;
    }

    for (int i = 1; i <= 20; i++)
    {
        dat[i] += dat[i - 1];
    }

    for (int i = 0; i < 10; i++)
    {
        cout << dat[i];
    }
    cout << endl;

    for (int i = n - 1; i >= 0; i--)
    {
        int num = arr[i];

        result[dat[num] - 1] = num;
        dat[num]--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i];
    }

    return 0;
}

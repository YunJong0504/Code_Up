#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    string arr[100];
    int count = 0;

    int start = 0;

    for (int i = 0; i <= str.size(); i++)
    {
        if (i == str.size() || str[i] == '_')
        {
            if (i > start)
            {
                arr[count] = str.substr(start, i - start);
                count++;
            }

            start = i + 1;
        }
    }

    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << "#" << arr[i] << endl;
    }

    return 0;
}

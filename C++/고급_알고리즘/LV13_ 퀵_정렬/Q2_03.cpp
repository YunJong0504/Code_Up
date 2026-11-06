#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input[5];
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> input[i];
    }

    for (int i = 0; i < 5; i++)
    {
        int pos = 0;

        while (true)
        {
            size_t index = input[i].find("MCD", pos);

            if (index == string::npos)
                break;

            count++;
            pos = index + 1;
        }
    }

    cout << count;

    return 0;
}

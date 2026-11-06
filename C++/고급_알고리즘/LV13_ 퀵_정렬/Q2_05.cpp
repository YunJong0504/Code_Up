#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    string before[5] = {"KFC", "MC", "BICMAC", "SHACK", "SONY"};

    string after[5] = {"#BBQ#", "#BBQ#", "#MACBOOK#", "#SHOCK#", "#NONY#"};

    for (int i = 0; i < 5; i++)
    {
        size_t pos = 0;

        while ((pos = str.find(before[i], pos)) != string::npos)
        {
            str.replace(pos, before[i].size(), after[i]);
            pos += after[i].size();
        }
    }

    cout << str;

    return 0;
}

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string str;
    cin >> str;

    bool check = true;
    string bad[3] = { "bad", "no", "puck" };

    for (int i = 0; i < 3; i++)
    {
        if (str.find(bad[i]) != string::npos)
        {
            check = false;
        }
    }

    int cnt = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '_')
        {
            cnt++;

            if (cnt > 5)
            {
                check = false;
            }
        }
        else
        {
            cnt = 0;
        }
    }

    int dat[256] = {};

    for (int i = 0; i < str.size(); i++)
    {
        unsigned char ch = str[i];

        if (isalpha(ch))
        {
            dat[ch]++;

            if (dat[ch] > 5)
            {
                check = false;
            }
        }

        if (isdigit(ch))
        {
            check = false;
        }
    }

    if (check)
        cout << "pass";
    else
        cout << "fail";

    return 0;
}

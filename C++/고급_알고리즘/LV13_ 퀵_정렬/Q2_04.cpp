#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    string result = "";

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        if (!result.empty())
        {
            char prev = result.back();

            if ((ch == '(' && prev == '(') ||
                (ch == ')' && prev == ')'))
            {
                continue;
            }
        }

        result += ch;
    }

    string temp = "";

    for (int i = 0; i < result.size(); i++)
    {
        if (i + 2 < result.size() &&
            result.substr(i, 3) == "^^^")
        {
            temp += "^^";
            i += 2;
        }
        else
        {
            temp += result[i];
        }
    }

    for (int i = 1; i + 1 < temp.size(); i++)
    {
        if (temp[i - 1] == '^' &&
            temp[i + 1] == '^' &&
            temp[i] != '_')
        {
            temp[i] = '_';
        }
    }

    cout << temp;

    return 0;
}

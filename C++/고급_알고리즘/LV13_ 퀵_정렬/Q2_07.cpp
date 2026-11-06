#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++)
    {
        str[i] = tolower(str[i]);
    }

    string start[2] = { "http://", "https://" };
    string end[4] = { ".com", ".co.kr", ".org", ".net" };

    int cnt = 0;

    for (int i = 0; i < str.size(); i++)
    {
        int len = 0;

        for (int j = 0; j < 2; j++)
        {
            if (str.substr(i, start[j].size()) == start[j])
            {
                len = start[j].size();
                break;
            }
        }

        if (len == 0)
            continue;

        int pos = i + len;

        for (int j = 0; j < 4; j++)
        {
            size_t index = str.find(end[j], pos);

            if (index != string::npos && index - pos >= 3)
            {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << "개";

    return 0;
}

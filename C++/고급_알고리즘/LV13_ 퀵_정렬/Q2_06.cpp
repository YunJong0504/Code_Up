#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string str;
    cin >> str;

    string word = "";
    string num = "";

    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))
        {
            if (!num.empty())
            {
                cout << word << "#" << stoi(num) + 17 << endl;

                word = "";
                num = "";
            }

            word += str[i];
        }
        else if (isdigit(str[i]))
        {
            num += str[i];
        }
    }

    if (!word.empty() && !num.empty())
    {
        cout << word << "#" << stoi(num) + 17 << endl;
    }

    return 0;
}

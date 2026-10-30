#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str;
        std::cin >> str;

        unordered_map<char, int> dic;

        int vowel = 0;
        bool check = true;

        for (int j = 0; j < str.size(); j++)
        {
            char ch = str[j];

            if (ch < 'a' || ch > 'z')
            {
                check = false;
                break;
            }

            dic[ch]++;

            if (dic[ch] > 2)
            {
                check = false;
                break;
            }

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowel++;
            }
        }

        if (vowel != 3)
        {
            check = false;
        }

        if (check)
            std::cout << "good" << std::endl;
        else
            std::cout << "no" << std::endl;
    }

    return 0;
}

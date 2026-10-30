#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

int main()
{
    string str;
    std::cin >> str;

    unordered_map<char, int> dic;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = toupper(str[i]);
        dic[ch]++;
    }

    for (char ch = 'A'; ch <= 'F'; ch++)
    {
        std::cout << ch << ":" << dic[ch] << std::endl;
    }

    return 0;
}

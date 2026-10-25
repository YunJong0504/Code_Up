#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int HashFunction(string str)
{
    int hash = 0;

    for (int i = 0; i < str.length(); i++)
    {
        hash = hash * 26 + str[i];
    }

    return hash;
}

int main()
{
    string str;
    std::cin >> str;

    cout << HashFunction(str);

    return 0;
}

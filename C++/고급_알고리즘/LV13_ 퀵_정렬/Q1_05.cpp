#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    string str = "BOBOOBOBOBOBBM";

    unordered_map<string, int> dic;

    for (int i = 0; i + 2 < str.size(); i++)
    {
        string word = str.substr(i, 3);
        dic[word]++;
    }

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        string word;
        std::cin >> word;

        std::cout << dic[word] << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    std::cin >> N;

    unordered_map<string, int> dic;

    string spy;
    int age1 = 0, age2 = 0;

    for (int i = 0; i < N; i++)
    {
        string name;
        int age;

        cin >> name >> age;

        if (dic.count(name) > 0)
        {
            spy = name;
            age1 = dic[name];
            age2 = age;
        }
        else
        {
            dic[name] = age;
        }
    }

    if (age1 > age2)
    {
        swap(age1, age2);
    }

    std::cout << spy << std::endl;
    std::cout << age1 << " " << age2;

    return 0;
}

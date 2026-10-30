#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> dic;

    // 팀원 명단 저장
    dic["POP"] = 1;
    dic["TOM"] = 1;
    dic["MC"] = 1;
    dic["JASON"] = 1;
    dic["KFC"] = 1;

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        string name;
        std::cin >> name;

        if (dic.count(name) > 0)
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }
    }

    return 0;
}

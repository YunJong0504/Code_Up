#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> dic;

    dic["1011"] = 1;
    dic["0011"] = 1;
    dic["1111"] = 1;
    dic["0000"] = 1;
    dic["1100"] = 1;

    string arr[5];

    for (int i = 0; i < 5; i++)
    {
        std::cin >> arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            string str = arr[i].substr(j, 4);

            if (dic.count(str) > 0)
            {
                std::cout << "yes";
                return 0;
            }
        }
    }

    cout << "no";

    return 0;
}

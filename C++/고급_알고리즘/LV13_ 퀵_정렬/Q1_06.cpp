#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    char map[6][6] = {
        {'A', 'B', 'A', 'B', 'A', 'B'},
        {'C', 'D', 'C', 'D', 'C', 'D'},
        {'A', 'G', 'G', 'F', 'H', 'A'},
        {'B', 'B', 'F', 'A', 'B', 'C'},
        {'D', 'D', 'C', 'C', 'D', 'D'},
        {'F', 'F', 'D', 'H', 'A', 'S'}
    };

    unordered_map<string, int> dic;

    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            string str = "";

            str += map[y][x];
            str += map[y][x + 1];
            str += map[y + 1][x];
            str += map[y + 1][x + 1];

            dic[str]++;
        }
    }

    string target = "";

    for (int i = 0; i < 4; i++)
    {
        char ch;
        std::cin >> ch;
        target += ch;
    }

    std::cout << dic[target];

    return 0;
}

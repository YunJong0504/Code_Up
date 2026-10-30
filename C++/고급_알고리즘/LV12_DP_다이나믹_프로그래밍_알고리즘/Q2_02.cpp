#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int money;
    std::cin >> money;

    int coin[4] = { 500,100,50,10 };
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        cnt += money / coin[i];
        money %= coin[i];
    }

    std::cout << cnt;

    return 0;
}

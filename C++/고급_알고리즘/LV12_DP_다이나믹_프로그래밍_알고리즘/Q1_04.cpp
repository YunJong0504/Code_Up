#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<long long, string> db;

    db[1000000005] = "Sour";
    db[1000000002] = "Dav";
    db[1000000003] = "Nica";
    db[1000000006] = "Timer";
    db[1000000015] = "Pico";
    db[1000000022] = "Topisl";
    db[1000000013] = "Whab";
    db[1000000009] = "Hap";

    long long age;
    std::cin >> age;

    std::cout << db[age];

    return 0;
}

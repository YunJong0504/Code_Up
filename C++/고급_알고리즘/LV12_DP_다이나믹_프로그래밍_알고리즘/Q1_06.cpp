#include <iostream>
using namespace std;

struct Node
{
    long long age;
    Node* next;
};

Node buf[100];
int bufCnt = 0;

Node* hashTable[10] = {};

Node* Alloc(long long age, Node* next)
{
    buf[bufCnt].age = age;
    buf[bufCnt].next = next;

    return &buf[bufCnt++];
}

void AddNode(long long age)
{
    int hash = age % 10;

    hashTable[hash] = Alloc(age, hashTable[hash]);
}

int main()
{
    long long ages[8] = {
        1000000005,
        1000000006,
        1000000035,
        1000000002,
        1000000011,
        1000000005,
        1000000015,
        1000000025,
    };

    for (int i = 0; i < 8; i++)
    {
        AddNode(ages[i]);
    }

    long long target;
    std::cin >> target;

    int hash = target % 10;
    int count = 0;

    Node* cur = hashTable[hash];

    while (cur != nullptr)
    {
        if (cur->age == target)
        {
            count++;
        }

        cur = cur->next;
    }

    std::cout << count << "마리";

    return 0;
}

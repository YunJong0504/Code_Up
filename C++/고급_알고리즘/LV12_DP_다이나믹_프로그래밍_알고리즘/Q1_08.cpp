#include <iostream>
using namespace std;

struct Node
{
    char code;
    int killCount;
    Node* next;
};

Node buf[100];
int bufCnt = 0;

Node* hashTable[26] = {};

Node* myAlloc(char code, int killCount, Node* next)
{
    buf[bufCnt].code = code;
    buf[bufCnt].killCount = killCount;
    buf[bufCnt].next = next;

    return &buf[bufCnt++];
}

void addNode(char code, int killCount)
{
    int hash = (code - 'A') % 26;

    hashTable[hash] = myAlloc(code, killCount, hashTable[hash]);
}

int search(char code)
{
    int hash = (code - 'A') % 26;

    Node* cur = hashTable[hash];

    while (cur != nullptr)
    {
        if (cur->code == code)
            return cur->killCount;

        cur = cur->next;
    }

    return -1;
}

int main()
{
    addNode('B', 10);
    addNode('Z', 160);

    char target;
    cin >> target;

    cout << search(target);

    return 0;
}

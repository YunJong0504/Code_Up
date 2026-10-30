#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node* next;
};

Node buf[100];
int bufCnt = 0;

Node* hashTable[100] = {};

unsigned int HashFunction(string str)
{
    unsigned int hash = 0;

    for (int i = 0; i < str.size(); i++)
    {
        hash = hash * 26 + str[i];
    }

    return hash % 100;
}

Node* myAlloc(string name, Node* next)
{
    buf[bufCnt].name = name;
    buf[bufCnt].next = next;

    return &buf[bufCnt++];
}

void addNode(string name)
{
    unsigned int hash = HashFunction(name);

    hashTable[hash] = myAlloc(name, hashTable[hash]);
}

bool search(string name)
{
    unsigned int hash = HashFunction(name);

    Node* cur = hashTable[hash];

    while (cur != nullptr)
    {
        if (cur->name == name)
        {
            return true;
        }

        cur = cur->next;
    }

    return false;
}

int main()
{
    addNode("POP");
    addNode("TOM");
    addNode("MC");
    addNode("JASON");
    addNode("KFC");

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string name;
        std::cin >> name;

        if (search(name))
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

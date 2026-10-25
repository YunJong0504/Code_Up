#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node* next;
};

Node buf[100];
int bufCnt = 0;

Node* head[5] = {};
Node* tail[5] = {};

Node* Alloc(int id)
{
    buf[bufCnt].id = id;
    buf[bufCnt].next = nullptr;

    return&buf[bufCnt++];
}

void AddNode(char group, int id)
{
    int idx = group - 'A';
    Node* now = Alloc(id);

    if (head[idx] == nullptr)
    {
        head[idx] = now;
        tail[idx] = now;
    }
    else
    {
        tail[idx]->next = now;
        tail[idx] = now;
    }
}

int main()
{
    char group[11] = "AEEAEBCCDA";
    int id[10] = { 21,15,6,15,34,32,35,36,14,3 };

    for (int i = 0; i < 10; i++)
    {
        AddNode(group[i], id[i]);
    }

    char target;
    std::cin >> target;

    int idx = target - 'A';

    Node* cur = head[idx];

    while (cur != nullptr)
    {
        std::cout << cur->id << " ";
        cur = cur->next;
    }

    return 0;
}

#include <iostream>
using namespace std;

struct Node
{
    char ch;
    Node* next;
};
Node buf[100];
int bufCnt;
Node* head;
Node* myAlloc(int ch, Node* next)
{
    buf[bufCnt].ch = ch;
    buf[bufCnt].next = next;
    return &buf[bufCnt++];
}

void addNode(char ch, Node* next)
{
    head = myAlloc(ch, head);
}

int main()
{
    addNode('E', head);
    addNode('D', head);
    addNode('C', head);
    addNode('B', head);
    addNode('A', head);

    Node* cur = head;

    while (cur != nullptr)
    {
        cout << cur->ch << " ";
        cur = cur->next;
    }

    return 0;
}

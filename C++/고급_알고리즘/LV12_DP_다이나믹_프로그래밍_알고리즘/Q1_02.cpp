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
    for (int i = 0; i < 9; i++)
    {
        char ch;
        std::cin >> ch;
        addNode(ch, head);
    }

    Node* cur = head;

    for (int i = bufCnt - 1; i >= 0; i -= 2)
    {
        std::cout << buf[i].ch << " ";
    }

    return 0;
}

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node buf[100];
int bufCnt;

Node* head = nullptr;
Node* tail = nullptr;

Node* Alloc(int data, Node* next)
{
    buf[bufCnt].data = data;
    buf[bufCnt].next = next;

    return &buf[bufCnt++];
}

void AddNode(int data)
{
    Node* cur = Alloc(data, nullptr);

    if (head == nullptr)
    {
        head = cur;
        tail = cur;
    }
    else
    {
        tail->next = cur;
        tail = cur;
    }
}

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;

        AddNode(num);
    }

    Node* cur = head;

    while (cur != nullptr)
    {
        std::cout << cur->data << " ";
        cur = cur->next;
    }

    return 0;
}

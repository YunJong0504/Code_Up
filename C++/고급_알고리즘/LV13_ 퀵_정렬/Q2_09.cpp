#include <iostream>
#include <string>
using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;

    if (A.size() < B.size())
    {
        swap(A, B);
    }

    for (int len = B.size(); len >= 1; len--)
    {
        for (int i = 0; i + len <= B.size(); i++)
        {
            string temp = B.substr(i, len);

            if (A.find(temp) != string::npos)
            {
                cout << temp;
                return 0;
            }
        }
    }

    return 0;
}

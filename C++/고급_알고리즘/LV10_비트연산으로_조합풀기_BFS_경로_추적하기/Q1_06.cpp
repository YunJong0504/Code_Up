#include <iostream>
#include <queue>
using namespace std;

int map[8][9];
int visited[8][9];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct Node
{
    int y;
    int x;
    int dist;
};

int main()
{
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            char c;
            cin >> c;

            if (c == '#')
                map[y][x] = 1;
            else
                map[y][x] = 0;
        }
    }

    queue<pair<int, int>> q;

    bool found = false;

    for (int y = 0; y < 8 && !found; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (map[y][x] == 1)
            {
                q.push({ y, x });
                visited[y][x] = 1;

                found = true;
                break;
            }
        }
    }

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= 8 ||
                nx < 0 || nx >= 9)
                continue;

            if (visited[ny][nx])
                continue;

            if (map[ny][nx] == 1)
            {
                visited[ny][nx] = 1;
                q.push({ ny, nx });
            }
        }
    }

    queue<Node> q2;

    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (visited[y][x] == 1)
            {
                q2.push({ y, x, 0 });
            }
        }
    }

    while (!q2.empty())
    {
        Node current = q2.front();
        q2.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = current.y + dy[i];
            int nx = current.x + dx[i];

            if (ny < 0 || ny >= 8 ||
                nx < 0 || nx >= 9)
                continue;

            if (map[ny][nx] == 1 &&
                visited[ny][nx] == 0)
            {
                cout << current.dist;
                return 0;
            }

            if (map[ny][nx] == 0 &&
                visited[ny][nx] == 0)
            {
                visited[ny][nx] = 2;

                q2.push({ ny, nx, current.dist + 1 });
            }
        }
    }

    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int map[7][7] =
{
    0,0,0,1,2,0,0,
    0,2,0,0,0,0,0,
    0,0,1,0,0,1,2,
    0,0,0,0,0,0,0,
    1,0,0,1,0,0,0,
    0,2,0,0,0,1,0,
    0,0,1,0,2,0,0,
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct Node
{
    int y, x;
    int dist;
};

bool bfs1(int sy, int sx)
{
    queue<Node> q;
    bool visited[7][7] = {};

	q.push({ sy, sx, 0 });
	visited[sy][sx] = true;

    while (!q.empty())
    {
		Node n = q.front();
        q.pop();

        if (n.dist >= 3)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = n.y + dy[i];
            int nx = n.x + dx[i];

            if (ny < 0 || ny >= 7 || nx < 0 || nx >= 7)
                continue;

            if (visited[ny][nx])
                continue;

            if (map[ny][nx] == 1)
                return false;

            if (map[ny][nx] == 0)
            {
                visited[ny][nx] == true;
                q.push({ ny,nx,n.dist + 1 });
            }
        }
    }

    return true;
}

bool bfs2(int sy, int sx)
{
    queue<Node> q;
    bool visited[7][7] = {};

    q.push({ sy, sx, 0 });
    visited[sy][sx] = true;

    while (!q.empty())
    {
        Node n = q.front();
        q.pop();

        if (n.dist >= 4)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = n.y + dy[i];
            int nx = n.x + dx[i];

            if (ny < 0 || ny >= 7 || nx < 0 || nx >= 7)
                continue;

            if (visited[ny][nx])
                continue;

            if (map[ny][nx] == 2)
                return false;

            if (map[ny][nx] == 0)
            {
                visited[ny][nx] == true;
                q.push({ ny,nx,n.dist + 1 });
            }
        }
    }

    return true;
}

int main()
{
    for (int y = 0; y < 7; y++)
    {
        for (int x = 0; x < 7; x++)
        {
            if (map[y][x] == 1)
            {
				if (!bfs1(y, x))
				{
                    cout << "fail";
					return 0;
				}
            }
            else if (map[y][x] == 2)
            {
                if (!bfs2(y, x))
                {
                    cout << "fail";
                    return 0;
                }
            }
        }
    }

    cout << "pass";

    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int map[5][5] =
{
    0,0,0,1,0,
    0,0,0,1,0,
    1,1,0,0,0,
    0,0,1,0,0,
    0,0,0,0,0,
};

bool visited[5][5][5][5] = {};

struct Node
{
    int ey, ex;
    int ay, ax;
    int time;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int bfs(int ey, int ex, int ay, int ax)
{
	queue<Node> q;
	q.push({ ey, ex, ay, ax, 0 });
	visited[ey][ex][ay][ax] = true;

	while (!q.empty())
	{
		Node cur = q.front();
		q.pop();

		if (cur.ey == cur.ay && cur.ex == cur.ax)
		{
			return cur.time;
		}

		for (int i = 0; i < 4; i++)
		{
			int ney = cur.ey + dy[i];
			int nex = cur.ex + dx[i];
			int nay = cur.ay + dy[i];
			int nax = cur.ax + dx[i];

			if (ney < 0 || ney >= 5 || nex < 0 || nex >= 5) 
				continue;
			if (nay < 0 || nay >= 5 || nax < 0 || nax >= 5)
				continue;
			if (map[ney][nex] == 1 || map[nay][nax] == 1) 
				continue;
			if (visited[ney][nex][nay][nax])
				continue;

			visited[ney][nex][nay][nax] = true;
			q.push({ ney, nex, nay, nax, cur.time + 1 });
		}
	}
	return -1;
}

int main()
{
	cout << bfs(0, 0, 4, 0);

    return 0;
}

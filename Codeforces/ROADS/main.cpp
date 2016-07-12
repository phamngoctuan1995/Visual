#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
#include <memory.h>

typedef pair<int, int> pii;
struct Node {
	int v, l, t;

	Node(int a, int b, int c)
	{
		v = a;
		l = b;
		t = c;
	}
};


int cost[101][10001];
bool fr[101][10001];

int main()
{
	int t;
	scanf("%d", &t);

	for (int tt = 0; tt < t; ++tt)
	{
		vector<Node> matrix[101];
		queue<pii> q;
		int k, n, e;
		//cin >> k >> n >> e;
		scanf("%d %d %d", &k, &n, &e);
		for (int i = 0; i < e; ++i)
		{
			int u, v, l, t;
			//cin >> u >> v >> l >> t;
			scanf("%d %d %d %d", &u, &v, &l, &t);
			matrix[u].push_back(Node(v, l, t));
		}

		memset(cost, -1, sizeof(cost));
		memset(fr, 0, sizeof(fr));

		q.push(pii(1, 0));
		cost[1][0] = 0;
		fr[1][0] = true;

		while (!q.empty())
		{
			pii u = q.front();
			q.pop();
			fr[u.first][u.second] = false;

			for (int i = 0; i < matrix[u.first].size(); ++i)
			{
				Node adj = matrix[u.first][i];
				if (u.second + adj.t > k)
					continue;
				if (cost[adj.v][u.second + adj.t] == -1 || cost[adj.v][u.second + adj.t] > cost[u.first][u.second] + adj.l)
				{
					cost[adj.v][u.second + adj.t] = cost[u.first][u.second] + adj.l;
					if (!fr[adj.v][u.second + adj.t])
					{
						fr[adj.v][u.second + adj.t] = true;
						q.push(pii(adj.v, u.second + adj.t));
					}
				}
			}
		}
		int res = -1;
		for (int kk = 0; kk <= k; ++kk)
			if ((cost[n][kk] != -1 && cost[n][kk] < res) || res == -1)
				res = cost[n][kk];

		//cout << res << endl;
		printf("%d\n", res);
	}

	return 0;
}
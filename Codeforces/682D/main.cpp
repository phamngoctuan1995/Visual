#include <iostream>
using namespace std;
#include <algorithm>
#include <string>

int f[1001][1001][11];
int g[1001][1001][11];

int main()
{
	int n, m, k;
	string s, t;
	cin >> n >> m >> k >> s >> t;

	s = '0' + s;
	t = '0' + t;

	for (int kk = 1; kk <= k; ++kk)
	{
		for (int nn = 1; nn <= n; ++nn)
		{
			for (int mm = 1; mm <= m; ++mm)
			{
				if (s[nn] == t[mm])
				{
					if (kk == 1 || f[nn - 1][mm - 1][kk - 1] > 0){
						g[nn][mm][kk] = f[nn - 1][mm - 1][kk - 1] + 1;
					}
					if (g[nn - 1][mm - 1][kk] > 0)
						g[nn][mm][kk] = max(g[nn][mm][kk], g[nn - 1][mm - 1][kk] + 1);
				}
			}
		}

		for (int nn = 1; nn <= n; ++nn)
			for (int mm = 1; mm <= m; ++mm)
			{
				f[nn][mm][kk] = max(f[nn - 1][mm][kk], f[nn][mm - 1][kk]);
				f[nn][mm][kk] = max(f[nn][mm][kk], g[nn][mm][kk]);
			}

	}

	cout << f[n][m][k];
	return 0;
}
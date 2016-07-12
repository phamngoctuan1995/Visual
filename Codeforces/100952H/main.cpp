#include <iostream>
using namespace std;

typedef long long ll;

ll f[251][251], res[251];

int main()
{
	for (int i = 0; i <= 250; ++i)
		f[i][i] = f[i][i] = 1;

	for (int i = 1; i <= 255; ++i)
		for (int j = 1; j <= i; ++j)
			for (int k = j; i + k <= 250; ++k)
			{
				f[i + k][k] += f[i][j];
			}

	for (int i = 1; i <= 250; ++i)
	{
		if (!(i & 1))
			for (int j = 1; j <= (i >> 1); ++j)
				res[i] += f[(i >> 1)][j];
		for (int j = 1; j <= i; ++j)
			if ((i - j) % 2 == 0)
				if (i - j == 0)
					res[i] ++;
				else
					for (int k = 1; k <= j; ++k)
						res[i] += f[(i - j) / 2][k];
	}

	while (1)
	{
		int n;
		cin >> n;
		if (!n)
			return 0;
		cout << res[n] << endl;


	}
	return 0;
}
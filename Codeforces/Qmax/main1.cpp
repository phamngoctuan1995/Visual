#include <stdio.h>
#include <algorithm>
using namespace std;

int ma[220000], mi[220000], preMax[220000][40], preMin[220000][40];
int logarit[220000];

void initLog(int n)
{
	int count = 2, id = 3, val = 1;
	while (1)
	{
		for (int j = 0; j < count; ++j)
		{
			logarit[id++] = val;
			if (id > n)
				break;
		}
		if (id > n)
			break;
		val += 1;
		count *= 2;
	}
}

void readMax(int n)
{
	for (int i = 1; i <= n; ++i)
		scanf("%d", ma + i);
}

void readMin(int n)
{
	for (int i = 1; i <= n; ++i)
		scanf("%d", mi + i);
}

void prepareMax(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		preMax[i][0] = ma[i];
		for (int j = 1; i - (1 << j) >= 0; ++j)
			preMax[i][j] = max(preMax[i][j - 1], preMax[i - (1 << (j - 1))][j - 1]);
	}
}

void prepareMin(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		preMin[i][0] = mi[i];
		for (int j = 1; i - (1 << j) >= 0; ++j)
			preMin[i][j] = min(preMin[i][j - 1], preMin[i - (1 << (j - 1))][j - 1]);
	}
}

int getMax(int l, int r)
{
	if (l == r)
		return ma[l];

	int exp = logarit[r - l + 1];
	return max(preMax[r][exp], preMax[l + (1 << exp) - 1][exp]);
}

int getMin(int l, int r)
{
	if (l == r)
		return mi[l];
	int exp = logarit[r - l + 1];
	return min(preMin[r][exp], preMin[l + (1 << exp) - 1][exp]);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	long long res = 0;
	scanf("%d", &n);
	readMax(n);
	readMin(n);
	
	initLog(n);

	prepareMax(n);
	prepareMin(n);

	for (int i = 1; i <= n; ++i)
	{
		int posl = -1, posr = -1;
		int l = 1, r = i;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (getMax(mid, i) < getMin(mid, i))
			{
				r = mid - 1;
			}
			else
				if (getMax(mid, i) > getMin(mid, i))
					l = mid + 1;
				else
				{
					posl = mid;
					r = mid - 1;
				}

		}

		l = 1, r = i;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (getMax(mid, i) < getMin(mid, i))
			{
				r = mid - 1;
			}
			else
				if (getMax(mid, i) > getMin(mid, i))
					l = mid + 1;
				else
				{
					posr = mid;
					l = mid + 1;

				}

		}

		if (posl != -1)
			res += posr - posl + 1;
	}

	printf("%lld", res);

	return 0;
}
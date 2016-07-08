#include <stdio.h>
#include <algorithm>
using namespace std;

int ma[220000], mi[220000], itmax[1000000], itmin[1000000];

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

void initMax(int l, int r, int k = 1)
{
	if (l == r)
	{
		itmax[k] = ma[l];
		return;
	}

	int mid = (l + r) / 2;
	initMax(l, mid, 2 * k);
	initMax(mid + 1, r, 2 * k + 1);
	itmax[k] = max(itmax[2 * k], itmax[2 * k + 1]);
}

void initMin(int l, int r, int k = 1)
{
	if (l == r)
	{
		itmin[k] = mi[l];
		return;
	}

	int mid = (l + r) / 2;
	initMin(l, mid, 2 * k);
	initMin(mid + 1, r, 2 * k + 1);
	itmin[k] = min(itmin[2 * k], itmin[2 * k + 1]);
}

int queryMax(int l, int r, int lq, int rq, int k = 1)
{
	if (l == lq && r == rq)
		return itmax[k];
	int mid = (l + r) / 2;

	if (lq > mid)
		return queryMax(mid + 1, r, lq, rq, 2 * k + 1);
	if (rq <= mid)
		return queryMax(l, mid, lq, rq, 2 * k);

	int max1 = queryMax(l, mid, lq, mid, 2 * k);
	int max2 = queryMax(mid + 1, r, mid + 1, rq, 2 * k + 1);

	return max(max1, max2);
}

int queryMin(int l, int r, int lq, int rq, int k = 1)
{
	if (l == lq && r == rq)
		return itmin[k];
	int mid = (l + r) / 2;

	if (lq > mid)
		return queryMin(mid + 1, r, lq, rq, 2 * k + 1);
	if (rq <= mid)
		return queryMin(l, mid, lq, rq, 2 * k);

	int min1 = queryMin(l, mid, lq, mid, 2 * k);
	int min2 = queryMin(mid + 1, r, mid + 1, rq, 2 * k + 1);

	return min(min1, min2);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	long long res = 0;
	scanf("%d", &n);
	readMax(n);
	readMin(n);

	initMax(1, n);
	initMin(1, n);

	for (int i = 1; i <= n; ++i)
	{
		int posl = -1, posr = -1;
		int l = 1, r = i;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (queryMax(1, n, mid, i) < queryMin(1, n, mid, i))
			{
				r = mid - 1;
			}
			else
				if (queryMax(1, n, mid, i) > queryMin(1, n, mid, i))
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
			if (queryMax(1, n, mid, i) < queryMin(1, n, mid, i))
			{
				r = mid - 1;
			}
			else
				if (queryMax(1, n, mid, i) > queryMin(1, n, mid, i))
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
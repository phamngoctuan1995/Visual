#include <iostream>
using namespace std;
#include <algorithm>

unsigned int arr[55000], temp[55000], it[120000];

void update(int n, int m)
{
	for (int i = 0; i < m; ++i)
	{
		int l, r, v;
		cin >> l >> r >> v;
		temp[l] += v;
		temp[r + 1] -= v;
	}

	int sum = 0;

	for (int i = 1; i <= n; ++i)
	{
		sum += temp[i];
		arr[i] = sum;
	}
}

void init(int l, int r, int k = 1)
{
	if (l == r)
	{
		it[k] = arr[l];
		return;
	}

	int mid = (l + r) / 2;
	init(l, mid, 2 * k);
	init(mid + 1, r, 2 * k + 1);
	it[k] = max(it[2 * k], it[2 * k + 1]);
}

unsigned int query(int l, int r, int lq, int rq, int k = 1)
{
	if (l == lq && r == rq)
		return it[k];
	int mid = (l + r) / 2;

	if (lq > mid)
		return query(mid + 1, r, lq, rq, 2 * k + 1);
	if (rq <= mid)
		return query(l, mid, lq, rq, 2 * k);

	unsigned int max1 = query(l, mid, lq, mid, 2 * k);
	unsigned int max2 = query(mid + 1, r, mid + 1, rq, 2 * k + 1);

	return max(max1, max2);
}

int main()
{
	//freopen("in.txt", "r", stdin);

	unsigned int n, m;
	cin >> n >> m;
	update(n, m);
	init(1, n);

	int p;
	cin >> p;

	for (int i = 0; i < p; ++i)
	{
		int lq, rq;
		cin >> lq >> rq;
		cout << query(1, n, lq, rq) << endl;
	}
	return 0;
}
#include <iostream>
using namespace std;
#include <math.h>

typedef long long ll;

ll Count(ll top)
{
	ll count = 0;
	for (ll i = 2; i * i * i <= top; ++i)
	{
		ll temp = i*i*i;
		count += top / temp;
	}

	return count;
}

int main()
{
	ll n;
	cin >> n;

	ll l = 8, r = 8 * n;
	
	while (l < r)
	{
		ll mid = (l + r) / 2;
		if (Count(mid) < n)
			l = mid + 1;
		else
			r = mid;
	}

	if (Count(l) == n)
		cout << l;
	else
		cout << -1;

	return 0;
}
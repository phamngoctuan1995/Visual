#include <iostream>
#include <deque>
using namespace std;

int a[20000];
int main()
{
	deque<int> queue;

	int m, n, k;
	cin >> m;

	for (int mm = 0; mm < m; ++mm)
	{
		cin >> n >> k;
		queue.clear();

		int num;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			while (!queue.empty() && a[i] <= a[queue.back()])
					queue.pop_back();
			queue.push_back(i);

			if (queue.front() <= i - k)
			{				
				queue.pop_front();
			}

			if (i >= k)
				cout << a[queue.front()] << " ";
		}
		cout << endl;
	}
	return 0;
}
#include <iostream>
using namespace std;
#include <vector>
typedef pair<int, int> pii;

pii number[] = { pii(3, 1), pii(0, 0), pii(0, 1), pii(0, 2), pii(1, 0), pii(1, 1), pii(1, 2), pii(2, 0), pii(2, 1), pii(2, 2) };
int check[4][3];

int main()
{
	for (int i = 0; i <= 9; ++i)
	{
		pii temp = number[i];
		check[temp.first][temp.second] = 1;
	}

	int m;
	vector<pii> interval;

	cin >> m;
	char old;
	cin >> old;
	for (int i = 1; i < m; ++i)
	{
		char nw;
		cin >> nw;
		pii interv = pii(number[nw - '0'].first - number[old - '0'].first, number[nw - '0'].second - number[old - '0'].second);
		interval.push_back(interv);
		old = nw;
	}

	int count = 0;

	for (int i = 0; i < 10; ++i)
	{
		pii beg = number[i];

		bool flag = true;

		for (int j = 0; j < interval.size(); ++j)
		{
			beg.first += interval[j].first;
			beg.second += interval[j].second;

			if (beg.first < 0 || beg.first >= 4 || beg.second < 0 || beg.second >= 3 || !check[beg.first][beg.second])
			{
				flag = false;
				break;
			}
		}

		if (flag)
			count += 1;
	}

	if (count == 1)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
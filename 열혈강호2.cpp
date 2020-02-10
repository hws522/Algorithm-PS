/*
백준 11376번. 이분 매칭 이용.
각각의 직원이 최대 두개의 일을 할 수 있다는 점에서 두번씩 DFS를 수행해주면 됨.
어떤 것을 먼저 매칭하던지 최종 매칭 숫자가 동일하므로 단순히 DFS를 두번만 수행하면 됨.
*/

/*
첫째 줄에 직원의 수 N과 일의 개수 M이 주어진다. (1 ≤ N, M ≤ 1,000)

둘째 줄부터 N개의 줄의 i번째 줄에는 i번 직원이 할 수 있는 일의 개수와 할 수 있는 일의 번호가 주어진다.
*/

#include<iostream>
#include<vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
int c[MAX];
int n, m;

bool dfs(int x)
{
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];

		if (c[y])
			continue;

		c[y] = true;

		if (d[y] == 0 || dfs(d[y]))
		{
			d[y] = x;

			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int k;

		cin >> k;

		for (int j = 1; j <= k; j++)
		{
			int y;

			cin >> y;

			a[i].push_back(y);
		}
	}
	int count = 0;

	for (int k = 0; k < 2; k++) //dfs 두번씩 수행하도록.
	{
		for (int i = 1; i <= n; i++)
		{
			fill(c, c + MAX, false);

			if (dfs(i))
				count++;
		}
	}
	cout << count << endl;

	return 0;
}
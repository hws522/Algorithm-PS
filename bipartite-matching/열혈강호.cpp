/*
백준 11375번. 이분 매칭 이용.
기초적인 이분 매칭 문제.
축사배정과 입력받는 방식만 다를 뿐 동일하게 DFS를 이용하여 해결.
*/

/*
첫째 줄에 직원의 수 N과 일의 개수 M이 주어진다. (1 ≤ N, M ≤ 1,000)
둘째 줄부터 N개의 줄의 i번째 줄에는 i번 직원이 할 수 있는 일의 개수와 할 수 있는 일의 번호가 주어진다.
*/

#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n, m; //직원 ,해야할 일.

bool dfs(int x)
{
	for (int i = 0; i < a[x].size(); i++)
	{
		int t = a[x][i];

		if (c[t])
			continue;

		c[t] = true;

		if (d[t] == 0 || dfs(d[t]))
		{
			d[t] = x;
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
			int t;

			cin >> t;

			a[i].push_back(t);
		}
	}
	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		fill(c, c + MAX, false);

		if (dfs(i))
			count++;
	}
	cout << count << endl;

	return 0;
}
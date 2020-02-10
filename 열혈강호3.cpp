/*
백준 11377번. 이분 매칭 이용.
특정한 직원에 한해서만 2번씩 일을 할 수 있도록 매칭.
모든직원에 대해 1번씩 매칭해준 후, 특정한 직원의 숫자 만큼만 추가적으로 한번더 매칭을 수행.
*/

/*
첫째 줄에 직원의 수 N과 일의 개수 M, 일을 2개할 수 있는 직원의 수 K가 주어진다. (1 ≤ N, M ≤ 1,000, 1 ≤ K ≤ N)

둘째 줄부터 N개의 줄의 i번째 줄에는 i번 직원이 할 수 있는 일의 개수와 할 수 있는 일의 번호가 주어진다.
*/

#include<iostream>
#include<vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n, m, k, s;

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
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> s;

		for (int j = 1; j <= s; j++)
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

	//2번씩 작업 할 수 있는 사람을 추가적으로 계산.
	int extra = 0;

	for (int i = 1; i <= n && extra < k; i++)
	{
		fill(c, c + MAX, false);

		if (dfs(i))
			extra++;
	}

	cout << count + extra << endl;

	return 0;
}

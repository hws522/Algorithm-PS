/*
���� 11376��. �̺� ��Ī �̿�.
������ ������ �ִ� �ΰ��� ���� �� �� �ִٴ� ������ �ι��� DFS�� �������ָ� ��.
� ���� ���� ��Ī�ϴ��� ���� ��Ī ���ڰ� �����ϹǷ� �ܼ��� DFS�� �ι��� �����ϸ� ��.
*/

/*
ù° �ٿ� ������ �� N�� ���� ���� M�� �־�����. (1 �� N, M �� 1,000)

��° �ٺ��� N���� ���� i��° �ٿ��� i�� ������ �� �� �ִ� ���� ������ �� �� �ִ� ���� ��ȣ�� �־�����.
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

	for (int k = 0; k < 2; k++) //dfs �ι��� �����ϵ���.
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
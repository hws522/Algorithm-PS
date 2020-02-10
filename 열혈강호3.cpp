/*
���� 11377��. �̺� ��Ī �̿�.
Ư���� ������ ���ؼ��� 2���� ���� �� �� �ֵ��� ��Ī.
��������� ���� 1���� ��Ī���� ��, Ư���� ������ ���� ��ŭ�� �߰������� �ѹ��� ��Ī�� ����.
*/

/*
ù° �ٿ� ������ �� N�� ���� ���� M, ���� 2���� �� �ִ� ������ �� K�� �־�����. (1 �� N, M �� 1,000, 1 �� K �� N)

��° �ٺ��� N���� ���� i��° �ٿ��� i�� ������ �� �� �ִ� ���� ������ �� �� �ִ� ���� ��ȣ�� �־�����.
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

	//2���� �۾� �� �� �ִ� ����� �߰������� ���.
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

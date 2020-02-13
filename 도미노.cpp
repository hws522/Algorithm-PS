/*
���� 4196��. SCC�̿�.
SCC�� �ƴ϶� SCC������ ���赵 ���ؾ� ��. 
���� ���� ���డ��.
���̳�� SCC�� �������� ���� ���� ������ �������� ��, 
���� ����(Indegree)�� 0�� ������ ������ ���� �Ǵ� ����.
��� SCC�� ���ؼ� ���� ������ȣ�� �Ű� �׷��� ���� ��,
������ �׷��� �ϳ��� �������� ���� �ܼ��� ���������� ������ �����ָ� ��.
���� �� �׷쿡 ���� ���������� ������ 0�� ��쿡�� ī��Ʈ�Ͽ� ���� ī��Ʈ ���.
*/

/*
ù ��° �ٿ� �׽�Ʈ ���̽��� ������ �־�����.

�� �׽�Ʈ ���̽��� ù ��° �ٿ��� �� ���� N, M�� �־����� �� ���� 100,000�� ���� �ʴ´�. 
N�� ���̳��� ������, M�� ������ ������ ��Ÿ����. ���̳� ����� ��ȣ�� 1�� N ������ ������. 
���� M���� �ٿ��� ���� �� ���� x, y�� �־����µ�, �̴� x�� ����� �Ѿ����� y�� ��ϵ� �Ѿ����� ���Ѵ�.

�� �׽�Ʈ ���̽����� �� �ٿ� ���� �ϳ��� ����Ѵ�. ������ ������ �Ѿ�߷��� �ϴ� �ּ��� ���̳� ��� �����̴�.
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>	
#define MAX 100001

using namespace std;

int n, m;
int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;
int group[MAX]; //�� �������� ��� ���ϴ��� ����.
bool inDegree[MAX]; //������ ���� ��, ���Ѱ��տ���� �������� üũ.

int dfs(int x)
{
	d[x] = ++id; //��帶�� ������ȣ ����.
	s.push(x); //���ÿ� �ڱ��ڽ� ����.

	int parent = d[x];

	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		//���� �湮���� ���� �̿� ����� ���.
		if (d[y] == 0)
			parent = min(parent, dfs(y));
		//�湮������, ���� ó�� ���� �̿� ����� ���.
		else if (!finished[y])
			parent = min(parent, d[y]);
	}

	if (parent == d[x])
	{
		vector<int> scc;

		while (1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			group[t] = SCC.size() + 1; //SCC�� ��� ���Ѱ��տ�Ҹ� ��� �迭�̹Ƿ�, �ε����� 0���� �����ϱ⶧��.
			finished[t] = true;

			if (t == x)
				break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main()
{
	int t; //�׽�Ʈ ���̽�.

	cin >> t;

	while (t--) //�׽�Ʈ ���̽��� �ݺ� �� �� ����.
	{
		SCC.clear();

		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, 0);
		fill(inDegree, inDegree + MAX, false);

		cin >> n >> m; //������ ������ ���� ����.

		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}

		for (int i = 0; i < m; i++)
		{
			int x, y; //� ���̳뿡�� � ���̳�� ������ �Ǿ� �ִ���.

			cin >> x >> y;

			a[x].push_back(y);
		}

		for (int i = 1; i <= n; i++)
		{
			if (d[i] == 0)
				dfs(i);
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < a[i].size(); j++)
			{
				int y = a[i][j];

				if (group[i] != group[y]) //�׷��� �ٸ��ٴ� ����
					inDegree[group[y]] = true; //���������� �����Ѵٴ� ��.
			}
		}
		int result = 0;

		for (int i = 1; i <= SCC.size(); i++)
		{
			if (!inDegree[i])
				result++;
		}
		cout << result << endl;
	}

	return 0;
}

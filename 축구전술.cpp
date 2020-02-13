/*
���� 3977��. SCC�̿�. ���̳빮���� ���� ����.
�ϳ��� SCC���� ����Ͽ� ��� �׷����� �湮�� �� ���� ���� ���ؼ� 
��� SCC�� ��� ���Ҹ� ����ϴ� ����. 
�׷��Ƿ� ������ ���� �����Ѵٰ� �������� ��, ���� ������ 0�� SCC�� ã���� ��.
���� ������ 0�� SCC�� �������̰ų�, �������� �ʴ� ��� ��Ȯ�� ���� ã�� �� ����(Confused)�� ���.
�ٽ� ����, ���� ������ 0�� SCC�� ���� �ϳ� ������ ������ �ش� SCC�� ��� ���Ҹ� ����ϴ� ��.
*/

/*
ù ��° �ٿ� �׽�Ʈ ���̽��� ������ �־�����, �̴� 11���� �۰ų� ���� �����̴�.
�� ���� �ٺ��� ���� ���� �׽�Ʈ ���̽��� �־����µ�, 
�� �׽�Ʈ ���̽����� ù ��° �ٿ� ������ �� N, ������ �������� �� M�� �־����� 1 �� N, M �� 100,000 �̴�. 
�� ���� M���� �ٿ� ���ļ� ������ (A, B)�� �־�����, A, B�� 0 �� A, B < N�� �����̴�.
�� �׽�Ʈ ���̽��� �ϳ��� �� �ٷ� ���еȴ�.

�� �׽�Ʈ ���̽����� ������ ��� ���� ������ ������������ �� �ٿ� �ϳ��� ����Ѵ�. 
���� �׷��� ���� ������ ������, "Confused"�� ����Ѵ�.
�� �׽�Ʈ ���̽��� ������ �ϳ��� �� ���� ����Ѵ�.
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
int group[MAX];
bool inDegree[MAX];
vector<int> result;

int dfs(int x)
{
	d[x] = ++id; //�� ��帶�� ������ȣ ����.
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
			group[t] = SCC.size() + 1;
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
	int t;

	cin >> t;

	while (t--)
	{
		SCC.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, 0);
		fill(inDegree, inDegree + MAX, false);
		result.clear();

		cin >> n >> m;

		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}

		for (int i = 0; i < m; i++)
		{
			int x, y;

			cin >> x >> y;

			a[x + 1].push_back(y + 1); //�� ������ 1���� �����ϵ��� ��������� + 1.
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

				if (group[i] != group[y])
					inDegree[group[y]] = true;
			}
		}
		int count = 0;

		for (int i = 0; i < SCC.size(); i++)
		{
			if (!inDegree[i + 1]) //Ư���� SCC�� ���������� ���� ���.
			{
				count++;

				for (int j = 0; j < SCC[i].size(); j++)
				{
					result.push_back(SCC[i][j] - 1);
				}
			}
		}
		sort(result.begin(), result.end());

		if (count != 1)
		{
			cout << "Confused\n" << endl;
		}
		else
		{
			for (int i = 0; i < result.size(); i++)
			{
				cout << result[i] << endl;
			}

			cout << endl;
		}	
	}
	return 0;
}
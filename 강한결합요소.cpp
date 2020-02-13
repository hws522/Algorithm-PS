/*
���� 2150��. ���� ���� ���(SCC) �̿�.
�ܼ��� Ư�� �׷��� �ȿ� ���ԵǾ� �ִ� ��� SCC�� ���� �ϳ��� ����ϴ� ����.
���� ���� ������ ��ȣ ������ ����ؾ� �ϹǷ� ���� �ʿ�.
*/

/*
ù° �ٿ� �� ���� V(1��V��10,000), E(1��E��100,000)�� �־�����. 
�̴� �׷����� V���� ������ E���� �������� �̷���� �ִٴ� �ǹ��̴�. 
���� E���� �ٿ��� ������ ���� ������ ��Ÿ���� �� ���� A, B�� �־�����. 
�̴� A�� ������ B�� ������ ����Ǿ� �ִٴ� �ǹ��̴�. �̶� ������ A->B�� �ȴ�.

ù° �ٿ� SCC�� ���� K�� ����Ѵ�. 
���� K���� �ٿ��� �� �ٿ� �ϳ��� SCC�� ���� ������ ��ȣ�� ����Ѵ�. 
�� ���� ������ -1�� ����Ͽ� �� ���� ���� ��Ÿ����. 
������ SCC�� ����� �� �� �ȿ� ���� �������� ������������ ����Ѵ�. 
���� ���� ���� SCC�� ���ؼ��� �� �ȿ� �����ִ� ���� ���� ������ ���� ��ȣ ������ ����Ѵ�.
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX]; //ó���� ��� ����.
vector<int> a[MAX]; //��� ������ ���� ����Ǿ� �ִ� ���� ���.
vector<vector<int> > SCC; 
stack<int> s;

//�׻� ó�� �湮�ϴ� ��常 �����. N�� ����.
int dfs(int x)
{
	d[x] = ++id; //��帶�� ������ ��ȣ ����.
	s.push(x); //���ÿ� �ڱ� �ڽ��� ����.

	int result = d[x];

	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		//���� �湮���� ���� �̿� ����� ���.
		if (d[y] == 0)
			result = min(result, dfs(y));
		//�湮������, ���� ó�� ���� �̿� ����� ���.
		else if (!finished[y])
			result = min(result, d[y]);
	}

	//�θ� ��尡 �ڱ� �ڽ��� ��� SCC�� ����.
	if (result == d[x])
	{
		vector<int> scc;

		while (1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;

			if (t == x)
				break;
		}

		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}

	//�ڽ��� �θ� ���� ��ȯ.
	return result;
}

int main()
{
	int v, e;

	cin >> v >> e;

	for (int i = 0; i < e; i++)
	{
		int x, y;

		cin >> x >> y;

		a[x].push_back(y);
	}

	for (int i = 1; i <= v; i++)
	{
		if (d[i] == 0)
			dfs(i);
	}

	cout << SCC.size() << endl;

	sort(SCC.begin(), SCC.end());

	for (int i = 0; i < SCC.size(); i++)
	{
		for (int j = 0; j < SCC[i].size(); j++)
		{
			cout << SCC[i][j] << ' ';
		}
		cout << -1 << endl;
	}

	return 0;
}
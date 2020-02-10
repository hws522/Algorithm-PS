/*
���� 1671��. �̺� ��Ī �̿�.
�ܼ��� 2���� ��Ī�� �����ϸ� ��.
������ �ɷ¿� ���� ��Ī�� ��Ű�� ���̹Ƿ� �ɷ� ��ġ �񱳺κ��� ����.
�� �� ��Ƹ����Ƿ� �� ���� ��Ī�� �Ǵ°��̶� ����.
*/

/*
ù° �ٿ� ����� ���� �� N�� �־�����. �� ���� 50���� �۰ų� ���� �ڿ����̴�. 

��° �ٺ��� �� ����� ũ��, �ӵ�, ������ ������ �־�����. �� ���� 2,000,000,000���� �۰ų� ���� �ڿ����̴�.
*/

#include<iostream>
#include<vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int state[MAX][3];
int d[MAX];
int c[MAX];
int n;

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
	cin >> n;

	for (int i = 1; i <= n; i++) //��� ���� ����.
	{
		cin >> state[i][0] >> state[i][1] >> state[i][2];
	}

	for (int i = 1; i <= n - 1; i++) //���� ����. �԰� ����.
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (state[i][0] == state[j][0] && state[i][1] == state[j][1] && state[i][2] == state[j][2])
				a[i].push_back(j);

			else if (state[i][0] >= state[j][0] && state[i][1] >= state[j][1] && state[i][2] >= state[j][2])
				a[i].push_back(j);

			else if (state[i][0] <= state[j][0] && state[i][1] <= state[j][1] && state[i][2] <= state[j][2])
				a[j].push_back(i);
		}
	}
	int count = 0; //�� ��Ƹ����� �ǹ�.
	
	for (int k = 0; k < 2; k++)//���� �ִ� �θ����� ����.
	{
		for (int i = 1; i <= n; i++)
		{
			fill(c, c + MAX, false);

			if (dfs(i))
				count++;
		}
	}
	cout << n - count << endl;

	return 0;
}
/*
백준 1671번. 이분 매칭 이용.
단순히 2번씩 매칭을 수행하면 됨.
상어들의 능력에 따라 매칭을 시키는 것이므로 능력 수치 비교부분을 수정.
상어가 상어를 잡아먹으므로 상어가 상어에게 매칭이 되는것이라 생각.
*/

/*
첫째 줄에 상어의 마리 수 N이 주어진다. 이 값은 50보다 작거나 같은 자연수이다. 

둘째 줄부터 각 상어의 크기, 속도, 지능의 정보가 주어진다. 이 값은 2,000,000,000보다 작거나 같은 자연수이다.
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

	for (int i = 1; i <= n; i++) //상어 스텟 설정.
	{
		cin >> state[i][0] >> state[i][1] >> state[i][2];
	}

	for (int i = 1; i <= n - 1; i++) //상어끼리 연결. 먹고 먹힘.
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
	int count = 0; //상어가 잡아먹힘을 의미.
	
	for (int k = 0; k < 2; k++)//상어는 최대 두마리만 먹음.
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
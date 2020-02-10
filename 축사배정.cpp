/*
백준 2188번. 이분 매칭 이용.
가장 기초적인 형태의 이분 매칭 문제.
DFS를 이용해서 계속 매칭이 가능한 경우를 재귀적으로 매칭시켜 문제 해결.
*/

/*
첫째 줄에 소의 수 N과 축사의 수 M이 주어진다. (1 ≤ N, M ≤ 200)
둘째 줄부터 N개의 줄에는 각 소가 들어가기 원하는 축사에 대한 정보가 주어진다. 
i번째 소가 들어가기 원하는 축사의 수 Si (0 ≤ Si ≤ M)이 먼저 주어지고, 이후 Si개의 축사 번호가 주어진다. 
같은 축사 번호가 두 번 이상 주어지는 경우는 없다.
*/

#include<iostream>
#include<vector>
#define MAX 201

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX]; //현재 확인한 노드인지 정보저장하는 배열.
int n, m, s;

// 매칭에 성공한 경우 true, 실패한 경우 false.
bool dfs(int x)
{
	//연결된 모든 노드에 대해서 들어갈 수 있는지 시도.
	for (int i = 0; i < a[x].size(); i++)
	{
		int t = a[x][i];
		//이미 처리한 노드는 볼 필요 없음.
		if (c[t])
			continue;

		c[t] = true;
		//비어있거나 점유 노드에 더 들어갈 공간이 있는 경우.
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
	cin >> n >> m; //소, 축사

	for (int i = 1; i <= n; i++)
	{
		cin >> s; //각각의 소들은 몇개의 축사를 원하는지.

		for (int j = 1; j <= s; j++)
		{
			int t;

			cin >> t; //특정한 소가 어떤 축사에 들어가고자 하는지.

			a[i].push_back(t);
		}
	}
	int count = 0; //매칭의 갯수.

	for (int i = 1; i <= n; i++)
	{
		fill(c, c + MAX, false); //한번의 단위 이분 매칭을 이용할 때 마다, c배열의 초기화.

		if (dfs(i)) //모든 소에 대해서 축사 배정하여 이분매칭 완료 될때마다 count++.
			count++;
	}

	cout << count << endl;

	return 0;
}
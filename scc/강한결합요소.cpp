/*
백준 2150번. 강한 결합 요소(SCC) 이용.
단순히 특정 그래프 안에 포함되어 있는 모든 SCC에 대해 하나씩 출력하는 문제.
가장 작은 정점의 번호 순으로 출력해야 하므로 정렬 필요.
*/

/*
첫째 줄에 두 정수 V(1≤V≤10,000), E(1≤E≤100,000)가 주어진다. 
이는 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다. 
다음 E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, B가 주어진다. 
이는 A번 정점과 B번 정점이 연결되어 있다는 의미이다. 이때 방향은 A->B가 된다.
첫째 줄에 SCC의 개수 K를 출력한다. 
다음 K개의 줄에는 각 줄에 하나의 SCC에 속한 정점의 번호를 출력한다. 
각 줄의 끝에는 -1을 출력하여 그 줄의 끝을 나타낸다. 
각각의 SCC를 출력할 때 그 안에 속한 정점들은 오름차순으로 출력한다. 
또한 여러 개의 SCC에 대해서는 그 안에 속해있는 가장 작은 정점의 정점 번호 순으로 출력한다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX]; //처리된 노드 저장.
vector<int> a[MAX]; //모든 정점에 대해 연결되어 있는 인접 노드.
vector<vector<int>> SCC;
stack<int> s;

//항상 처음 방문하는 노드만 실행됨. N번 수행.
int dfs(int x)
{
	d[x] = ++id; //노드마다 고유한 번호 지정.
	s.push(x);	 //스택에 자기 자신을 넣음.

	int result = d[x];

	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		//아직 방문하지 않은 이웃 노드인 경우.
		if (d[y] == 0)
			result = min(result, dfs(y));
		//방문했으나, 아직 처리 중인 이웃 노드인 경우.
		else if (!finished[y])
			result = min(result, d[y]);
	}

	//부모 노드가 자기 자신인 경우 SCC를 형성.
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

	//자신의 부모 값을 반환.
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
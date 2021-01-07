/*
백준 3977번. SCC이용. 도미노문제와 거의 같음.
하나의 SCC에서 출발하여 모든 그래프를 방문할 수 있을 때에 한해서 
출발 SCC의 모든 원소를 출력하는 문제. 
그러므로 문제에 답이 존재한다고 가정했을 때, 진입 차수가 0인 SCC를 찾으면 됨.
진입 차수가 0인 SCC가 여러개이거나, 존재하지 않는 경우 정확한 답을 찾을 수 없다(Confused)를 출력.
다시 말해, 진입 차수가 0인 SCC가 오직 하나 존재할 때에만 해당 SCC의 모든 원소를 출력하는 것.
*/

/*
첫 번째 줄에 테스트 케이스의 개수가 주어지며, 이는 11보다 작거나 같은 정수이다.
그 다음 줄부터 여러 개의 테스트 케이스가 주어지는데, 
각 테스트 케이스마다 첫 번째 줄에 구역의 수 N, 지시한 움직임의 수 M이 주어지며 1 ≤ N, M ≤ 100,000 이다. 
그 다음 M개의 줄에 걸쳐서 움직임 (A, B)가 주어지며, A, B는 0 ≤ A, B < N인 정수이다.
각 테스트 케이스는 하나의 빈 줄로 구분된다.
각 테스트 케이스마다 가능한 모든 시작 구역을 오름차순으로 한 줄에 하나씩 출력한다. 
만약 그러한 시작 구역이 없으면, "Confused"를 출력한다.
각 테스트 케이스의 끝에는 하나의 빈 줄을 출력한다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 100001

using namespace std;

int n, m;
int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;
int group[MAX];
bool inDegree[MAX];
vector<int> result;

int dfs(int x)
{
	d[x] = ++id; //각 노드마다 고유번호 지정.
	s.push(x);	 //스택에 자기자신 삽입.

	int parent = d[x];

	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		//아직 방문하지 않은 이웃 노드인 경우.
		if (d[y] == 0)
			parent = min(parent, dfs(y));
		//방문했으나, 아직 처리 중인 이웃 노드인 경우.
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

			a[x + 1].push_back(y + 1); //각 정점이 1부터 시작하도록 만들기위해 + 1.
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
			if (!inDegree[i + 1]) //특정한 SCC의 진입차수가 없는 경우.
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
			cout << "Confused\n"
				 << endl;
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
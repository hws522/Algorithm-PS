/*
백준 4196번. SCC이용.
SCC뿐 아니라 SCC사이의 관계도 구해야 함. 
위상 정렬 수행가능.
도미노는 SCC를 정점으로 보고 위상 정렬을 수행했을 때, 
진입 차수(Indegree)가 0인 정점의 갯수를 세면 되는 문제.
모든 SCC에 대해서 각각 고유번호를 매겨 그룹을 만든 뒤,
각각의 그룹을 하나의 정점으로 보고 단순히 진입차수의 갯수만 세어주면 됨.
이후 각 그룹에 대해 진입차수의 갯수가 0인 경우에만 카운트하여 최종 카운트 출력.
*/

/*
첫 번째 줄에 테스트 케이스의 개수가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 두 정수 N, M이 주어지며 두 수는 100,000을 넘지 않는다. 
N은 도미노의 개수를, M은 관계의 개수를 나타낸다. 도미노 블록의 번호는 1과 N 사이의 정수다. 
다음 M개의 줄에는 각각 두 정수 x, y가 주어지는데, 이는 x번 블록이 넘어지면 y번 블록도 넘어짐을 뜻한다.
각 테스트 케이스마다 한 줄에 정수 하나를 출력한다. 정답은 손으로 넘어뜨려야 하는 최소의 도미노 블록 개수이다.
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
int group[MAX];		//각 정점들이 어디에 속하는지 설정.
bool inDegree[MAX]; //각각의 정점 즉, 강한결합요소의 진입차수 체크.

int dfs(int x)
{
	d[x] = ++id; //노드마다 고유번호 지정.
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
			group[t] = SCC.size() + 1; //SCC는 모든 강한결합요소를 담는 배열이므로, 인덱스가 0부터 시작하기때문.
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
	int t; //테스트 케이스.

	cin >> t;

	while (t--) //테스트 케이스가 반복 될 때 마다.
	{
		SCC.clear();

		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, 0);
		fill(inDegree, inDegree + MAX, false);

		cin >> n >> m; //정점과 간선에 대한 정보.

		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}

		for (int i = 0; i < m; i++)
		{
			int x, y; //어떤 도미노에서 어떤 도미노로 연결이 되어 있는지.

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

				if (group[i] != group[y])	   //그룹이 다르다는 것은
					inDegree[group[y]] = true; //진입차수가 존재한다는 뜻.
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
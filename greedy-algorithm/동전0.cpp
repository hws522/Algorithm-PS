/*
백준 11047번. 그리디 알고리즘 이용.
거스름 돈으로 줄 수 있는 화폐의 종류도 입력으로 받기 때문에
화폐의 종류를 담을 수 있는 배열을 하나 추가 생성.
화폐의 가치가 큰 것부터 나누어주어야 하므로 처리할 때는 순서를 거꾸로 처리.
*/

/*
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. 
(1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

int main()
{
	int n, k;
	int result = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++) //화폐종류.
	{
		int x;

		cin >> x;

		a.push_back(x);
	}

	for (int i = a.size() - 1; i >= 0; i--)
	{
		result += k / a[i];

		k %= a[i];
	}
	cout << result;

	return 0;
}
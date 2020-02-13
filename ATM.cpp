/*
백준 11399번. 그리디 알고리즘 이용.
모든 사람이 돈을 인출할 때 필요한 시간의 합이 가장 작은 경우를 구하는 것.
인출하는 데 걸리는 시간이 적은 순서대로 정렬한 뒤, 시간의 합을 구하면 됨.
*/

/*
첫째 줄에 사람의 수 N(1 ≤ N ≤ 1,000)이 주어진다. 
둘째 줄에는 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어진다. (1 ≤ Pi ≤ 1,000)

첫째 줄에 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 출력한다.
*/

#include<iostream>
#include<algorithm>

using namespace std;

int a[1000]; //최대 인원.

int main()
{
	int n, sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n; i++)
	{
		sum += a[i] * (n - i); 
	}
	cout << sum << endl;

	return 0;
}
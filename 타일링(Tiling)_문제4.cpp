/*
다이나믹 프로그래밍 기법의 기본.
dp를 사용할 때에는 기본적으로 규칙성을 찾아서 그 규칙성으로 점화식을 세우는게 가장 중요.
백준 온라인 저지 참조.

2×n 크기의 직사각형을 2×1, 1×2, 1×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

입력 : 첫째 줄에 N(1 ≤ N ≤ 1,000,000)이 주어진다.
출력 : 첫째 줄에 경우의 수를 1,000,000,007로 나눈 나머지를 출력한다.
*/

#include<iostream>

using namespace std;

long long int d[1000001][2]; //시간이 오래 걸릴 수 있기 때문에 이중으로 만든다.

long long int dp(int x) //점화식 : D[n] = 3*D[n - 2] + 2*D[n - 1] + (2*D[n - 3] + 2*D[n - 4]...2*D[0])
{
	d[0][0] = 1;
	d[1][0] = 2;
	d[2][0] = 7;
	d[2][1] = 0;

	for (int i = 3; i <= x; i++)
	{
		d[i][0] = (3 * d[i - 2][0] + 2 * d[i - 1][0] + 2 * d[i][1]) % 1000000007;
		d[i][1] = (d[i - 1][1] + d[i - 3][0]) % 1000000007;
	}

	return d[x][0];
}

int main()
{
	int number;

	cin >> number;

	cout << dp(number) << endl;

	return 0;
}

/* //단일 다이나믹 프로그래밍 사용했을 때. 오류는 없으나, 느리다.
#include<iostream>

using namespace std;

long long int d[1000001];

long long int dp(int x) 
{
	if(x == 0)
		return 1;
	if(x == 1)
		return 2;
	if(x == 2)
		return 7;
	if(d[x] > 0)
		return d[x];

	long long int result = 3 * dp(x - 2) + 2 * dp(x - 1);

	for (int i = 3; i <= x; i++)
	{
		result += (2 * dp(x - i)) % 1000000007;
	}

	return d[x] = result % 1000000007;
}

int main()
{
	int number;

	cin >> number;

	cout << dp(number) << endl;

	return 0;
}
*/


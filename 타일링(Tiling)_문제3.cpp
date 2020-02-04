/*
다이나믹 프로그래밍 기법의 기본.
dp를 사용할 때에는 기본적으로 규칙성을 찾아서 그 규칙성으로 점화식을 세우는게 가장 중요.
백준 온라인 저지 참조.

3×n 크기의 직사각형을 2×1, 1×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

입력 : 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 30)
출력 : 경우의 수를 출력한다.
*/


#include<iostream>

using namespace std;

int d[30];

int dp(int x) // 점화식 : D[n] = 3*D[n - 2] + (2*D[n - 4] + 2*D[n - 6] ...2*D[0])
{
	if (x == 0)
		return 1;
	if (x == 1)
		return 0;
	if (x == 2)
		return 3;
	if (d[x] != 0)
		return d[x];

	int result = 3 * dp(x - 2); //점화식에 맞춤.

	for (int i = 3; i <= x; i++)
	{
		if (i % 2 == 0)
			result += 2 * dp(x - i);
	}

	return d[x] = result;
}

int main()
{
	int number;

	cin >> number;

	cout << dp(number) << endl;

	return 0;
}
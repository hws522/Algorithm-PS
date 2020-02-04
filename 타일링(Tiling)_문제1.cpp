/*
다이나믹 프로그래밍 기법의 기본.
dp를 사용할 때에는 기본적으로 규칙성을 찾아서 그 규칙성으로 점화식을 세우는게 가장 중요.
백준 온라인 저지 참조.

2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

입력 : 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)
출력 : 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
*/

#include<iostream>

using namespace std;

int arr[1001]; //최대 n의 갯수가 1000이므로. 

int dp(int x) // 점화식 : D[n] = D[n - 1] + D[n - 2]
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 2;
	if (arr[x] != 0)
		return arr[x];

	return arr[x] = (dp(x - 1) + dp(x - 2)) % 10007; //값이 매우 커지기 때문에 문제에서 10007을 나눈 나머지를 출력하는 출력방식을 제시함.
}

int main()
{
	int number;

	cin >> number;

	cout << dp(number) << endl;


	return 0;
}
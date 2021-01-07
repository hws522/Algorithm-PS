/*
백준 2217번. 그리디 알고리즘 이용.
최대 중량을 구하는 문제. 최대 중량을 구하려면 모든 로프의 가용 용량을 기준으로 오름차순 정렬.
이후 로프의 갯수를 용량이 작은 것을 하나씩 빼가며 최대 중량을 갱신해주면 됨.
*/

/*
첫째 줄에 정수 N이 주어진다. 
다음 N개의 줄에는 각 로프가 버틸 수 있는 최대 중량이 주어진다. 
이 값은 10,000을 넘지 않는 정수이다.
첫째 줄에 답을 출력한다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		if (max < a[i] * (n - i)) //버틸 수 있는 최대 중량은 전체로프중에서 가장 약한로프의 n배이므로.
			max = a[i] * (n - i); //모든 로프를 사용하지 않아도 되므로 조건을 넣어줌.
	}

	cout << max << endl;

	return 0;
}
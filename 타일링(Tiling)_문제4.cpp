/*
���̳��� ���α׷��� ����� �⺻.
dp�� ����� ������ �⺻������ ��Ģ���� ã�Ƽ� �� ��Ģ������ ��ȭ���� ����°� ���� �߿�.
���� �¶��� ���� ����.

2��n ũ���� ���簢���� 2��1, 1��2, 1��1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է� : ù° �ٿ� N(1 �� N �� 1,000,000)�� �־�����.
��� : ù° �ٿ� ����� ���� 1,000,000,007�� ���� �������� ����Ѵ�.
*/

#include<iostream>

using namespace std;

long long int d[1000001][2]; //�ð��� ���� �ɸ� �� �ֱ� ������ �������� �����.

long long int dp(int x) //��ȭ�� : D[n] = 3*D[n - 2] + 2*D[n - 1] + (2*D[n - 3] + 2*D[n - 4]...2*D[0])
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

/* //���� ���̳��� ���α׷��� ������� ��. ������ ������, ������.
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


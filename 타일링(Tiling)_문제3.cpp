/*
���̳��� ���α׷��� ����� �⺻.
dp�� ����� ������ �⺻������ ��Ģ���� ã�Ƽ� �� ��Ģ������ ��ȭ���� ����°� ���� �߿�.
���� �¶��� ���� ����.

3��n ũ���� ���簢���� 2��1, 1��2 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է� : ù° �ٿ� n�� �־�����. (1 �� n �� 30)
��� : ����� ���� ����Ѵ�.
*/


#include<iostream>

using namespace std;

int d[30];

int dp(int x) // ��ȭ�� : D[n] = 3*D[n - 2] + (2*D[n - 4] + 2*D[n - 6] ...2*D[0])
{
	if (x == 0)
		return 1;
	if (x == 1)
		return 0;
	if (x == 2)
		return 3;
	if (d[x] != 0)
		return d[x];

	int result = 3 * dp(x - 2); //��ȭ�Ŀ� ����.

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
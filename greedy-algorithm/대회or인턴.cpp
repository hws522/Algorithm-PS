#include<iostream>

using namespace std;

int main()
{
    int n , m , k;
    int count = 0;

    cin >> n >> m >> k;

    while(true)
    {
        if(k <= (n - 2 + m - 1) && n >= 2 && m >= 1)
        {
            n -= 2;
            m -= 1;
            count++;
        }
        else
            break;
    }

    cout << count << endl;

    return 0;
}
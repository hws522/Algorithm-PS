#include<iostream>

using namespace std;

int main()
{
    string a, b;

    int cnt = 50;
     

    cin >> a >> b;

    for(int i = 0; i <= b.size() - a.size(); i++)
    {
        int result = 0;

        for(int j = 0; j < a.size(); j++)
        {
            if(a[j] != b[j + i])
                result++;
        }

        cnt = min(cnt, result);
    }

    cout << cnt << endl;

    return 0;
}
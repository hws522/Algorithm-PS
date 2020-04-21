#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


bool compare(char a, char b)
{
    if(a > b)
        return true;

    return false;
}

int main()
{
    string s;
    int sum = 0;

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        sum += s[i] - '0';
    }

    if (sum % 3 != 0 || count(s.begin(), s.end(), '0') == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    else
        sort(s.begin(), s.end(), compare);

    cout << s << endl;

    return 0;
}
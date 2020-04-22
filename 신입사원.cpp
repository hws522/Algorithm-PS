#include<iostream>
#include<algorithm>
#define MAX 100000

using namespace std;

pair<int, int> person[MAX];

int main()
{
    int t, n;

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> person[i].first >> person[i].second;

        sort(person, person + n);

        int count = 1;
        int rank = person[0].second;

        for(int i = 1; i < n; i++)
        {
            if(person[i].second < rank)
            {
                count++;
                rank = person[i].second;
            }
        }
        cout << count << endl;
    }


    return 0;
}
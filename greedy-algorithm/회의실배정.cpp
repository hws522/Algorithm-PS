/*
백준 1931번. 그리디 알고리즘 이용. 
그리디 알고리즘 문제이기 때문에, 어떻게 하면 최대한 많이 우겨넣을 수 있을 지 생각 해봄.
반례가 없어야함.
공책에 예를 들어서 써보기로 함.
회의가 일찍 시작하는 순으로 정렬해도 늦게 끝나는 회의 때문에 안됨.
회의가 짧은 순으로 정렬하더라도 겹치는 경우엔 해당시키지 못함.
일찍 끝나는 순으로 정렬하면 될 것 같아서 해봄.
시간복잡도가 O(n^2)이므로 일반적으로 반복문을 돌리게 되면 시간 초과가 나올 수 있음. 
*/

/*
한개의 회의실에서 이를 사용하고자 하는 N개의 회의에 대하여 사용표를 만들고자 함.
각 회의 I에 대해 시작시간과 종료시간이 주어져 있고, 
각 회의가 겹치지 않으면서 회의실을 이용할 수 있는 최대 개수를 찾는 것.
회의가 끝나는 동시에 시작 될 수 있으며 회의는 중간에 끝날 수 없음.
회의 시작시간과 끝나는 시간이 같을 수도 있음.(시작하자마자 끝나는 것)
*/

/*
첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다. 
둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다. 
시작 시간과 끝나는 시간은 2^31-1보다 작거나 같은 자연수 또는 0이다.
첫째 줄에 최대 사용할 수 있는 회의의 최대 개수를 출력한다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class time
{
public:
    int start;  //시작 시간.
    int finish; //종료 시간.
};

bool compare(time a, time b)
{
    if (a.finish == b.finish)
        return a.start < b.start; // 종료 시간이 같다면, 시작 시간이 빠른 순.

    else
        return a.finish < b.finish; // 종료 시간이 다르다면, 종료 시간이 빠른 순.
}

int main()
{
    int n; // 회의 수.

    cin >> n; // 회의 수 입력.

    vector<time> t(n);

    for (int i = 0; i < n; i++)
    {
        cin >> t[i].start >> t[i].finish;
    }

    sort(t.begin(), t.end(), compare);

    int count = 0; // 최대 회의 수.
    int stop = 0;  // 회의 종료 시점.

    for (int i = 0; i < t.size(); i++)
    {
        if (stop <= t[i].start) //회의 종료 시점이 다음 시작 지점보다 작으면
        {                       //(0부터 시작이니까 바로 카운트 들어감.)
            stop = t[i].finish; //다음 회의 종료 시점 저장.
            count++;            //회의 수 증가.
        }
    }

    cout << count << endl;

    return 0;
}
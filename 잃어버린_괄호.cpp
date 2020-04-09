/*
백준 1541번. 그리디 알고리즘 이용.
*/

/*
양수와 +, -, ()를 가지고 길이가 최대 50인 식을 만듬.
괄호를 모두 지운 뒤, 다시 괄호를 쳤을 때 이 식의 최소값을 구하는 프로그램을 작성하는 것.
*/

/*
첫째 줄에 식이 주어진다. 
식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 
그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 
수는 0으로 시작할 수 있다.

첫째 줄에 정답을 출력한다.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 50

using namespace std;

class calculate
{
public:
    int num; //숫자
    char pm; //연산자 +,-
};

int main()
{
    vector<calculate> c(MAX); //문자와 숫자 구별해서 넣을 벡터.
    vector<int> vec(MAX); //자릿수 포함 숫자를 넣을 벡터.

    string s; //전체 식을 문자열로 받음.

    int number = 0; 
    int result = 0;
    
    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != '+' && s[i] != '-')
        {
            c[i].num = s[i] - '0'; //문자를 숫자로 바꾸어 넣기 위해.
        }

        else
        {
            c[i].pm = s[i];
        }
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(c[i].pm != '+' && c[i].pm != '-')
        {
            if(i != 0)
                number *= 10;

            number += c[i].num;  //연산자가 아닐 경우 number에 자릿수포함 숫자 삽입.
        }

        else if(c[i].pm == '+' || c[i].pm == '-')
        {
            vec[i] = number; //연산자가 나왔을 경우 전까지 나온 숫자를 vec에 삽입.
            number = 0;      //number 초기화.
        }

        if(i == s.size() - 1)
        {
            vec[s.size() - 1] = number; //연산자가 더이상 없을 경우, vec에 number 삽입.   
        }
    }

    number = 0; //number 초기화 해서 다른 연산에 사용.


    for(int i = s.size(); i > 0; i--)
    {
        if(c[i].pm != '-')
        {
            number += vec[i]; //전체 식 끝부터 '-'가 나오기 전까지 그 합을 number에 삽입.
        }

        else if(c[i].pm == '-') //'-'연산자가 나오면 지금까지 합한 수를 음수화 해준 뒤 result에 삽입.
        {
            result += -number;
            number = vec[i]; //다시 연산시작.
        }

        if(i == 1)
        {
            result += number; //for문이 끝난 뒤, 마지막 숫자를 result에 삽입.
        }
    }

    cout << result << endl; //결과값 출력.

    return 0;
}
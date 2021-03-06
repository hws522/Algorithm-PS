/*
백준 1541번. 그리디 알고리즘 이용. 
처음에는 그저 문자열로 다받은 뒤에 숫자 따로 문자 따로 분리하고, 그 숫자를 자릿수포함하는 숫자로 다시 만들어서
'-'기호가 다시 나올때까지 더해주고 '+' 기호가 나오면 그 값을 음수로 바꿔주고 따로 저장해놓고 더하고 
이런식으로 구현을 했었는데 결과적으로 제대로 구현도 하지 못함.
stoi를 제대로 쓸 줄도 몰랐던 탓도 있고, 더 쉽게 생각하려 했어야 했는데 참 부족하다는 걸 느낌.
결과적으로 전체 식을 입력 받았을 때, '-'를 기준으로 묶으면 되는데 이것도 한번 더 보면 
첫번째 연산자가 '-'일 때는 첫번째 수에서 나머지 수를 모두 빼주면 되고, 
'+'연산자 일때는 '-'연산자가 나올 때까지 더한 뒤에 '-'연산자 뒤의 숫자들을 모두 빼주면 됨.
결국 '-'연산자 기준으로 모두 묶을 것이고 결국 음수 처리 되기 때문.
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

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;         //전체 식을 받을 문자열 s.
    string temp = ""; //전체 식에서 숫자만 골라서 넣을 문자열 temp.

    bool btn = true; //'-'연산자가 나오기 전까지 조건문을 돌릴 때 필요한 bool.

    int result = 0; //결과값.

    cin >> s; //전체 식 입력.

    for (int i = 0; i <= s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == NULL) //숫자가 아닐 경우. 문자열 끝은 NULL값이기에 포함시켜줌.
        {
            if (btn) //'-'연산자가 나오지 않았을 때. '+'라는 뜻.
            {
                result += stoi(temp); //temp 에 들어있는 문자열 숫자들을 숫자로 변환시켜 result에 삽입.
                temp = "";            //temp 초기화.

                if (s[i] == '-') //'-'연산자가 나왔으니 이제 부터 빼주기만 하면 되므로 위의 조건문은 필요가 없음. 그래서 false로 바꿔줌.
                    btn = false;
            }
            else
            {
                result -= stoi(temp); //계속 빼줌.
                temp = "";
            }
        }
        else              //숫자일 경우.
            temp += s[i]; //문자열도 합쳐짐.
    }

    cout << result << endl; //결과값 출력.

    return 0;
}
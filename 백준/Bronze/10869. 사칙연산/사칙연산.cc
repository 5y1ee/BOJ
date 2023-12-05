//첫째 줄에 A+B, 둘째 줄에 A-B, 셋째 줄에 A*B, 넷째 줄에 A/B, 다섯째 줄에 A%B를 출력한다.
#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    cout << a+b << "\n" << a-b << "\n" << a*b << "\n" << a/b << "\n" << a%b;
}
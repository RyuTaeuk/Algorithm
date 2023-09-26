#include <iostream>
#include <utility>
#include <stack>
using namespace std;

void sol(string str) {
    stack<char> s;
    int result = 0;

    s.push(str[0]); //처음은 무조건 '('

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push(str[i]);
        }
        else if (str[i - 1] == '(' && str[i] == ')') {
            s.pop();
            result += s.size();
        } //레이저
        else if (str[i - 1] == ')' && str[i] == ')') {
            s.pop();
            result++;
        } // stick의 끝
    }
    cout << result << '\n';
}

int main(void) {
    string str;
    cin >> str;
    sol(str);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    stack<char> st;
    int result = 0, temp = 1;
    //'덧셈' 이 발생하는 조건 == 괄호가 닫히고 다시 열릴 때
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') {
            temp *= 2;
            st.push(s[i]);
        }
        else if (s[i] == '['){
            temp *= 3;
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            if(st.empty() || st.top() != '(') {
                result = 0;
                break;
            }
            else if(s[i-1] == '(') {
                result += temp;
                temp /= 2;
                st.pop();
            }
            else {
                temp /= 2;
                st.pop();
            }
        }
        else if (s[i] == ']') {
            if(st.empty() || st.top() != '[') {
                result = 0;
                break;
            }
            else if(s[i-1] == '[') {
                result += temp;
                temp /= 3;
                st.pop();
            }
            else {
                temp /= 3;
                st.pop();
            }
        }
    }
    if(!st.empty()) result = 0;
    cout << result << '\n';
    return 0;
}
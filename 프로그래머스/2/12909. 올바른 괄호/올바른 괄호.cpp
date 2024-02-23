#include<string>
#include<iostream>
#include<stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    for(int i = 0; i<s.size(); i++){
        if (s[i] == '('){
            st.push('(');
        }
        else if (s[i] == ')' && !st.empty()){
            st.pop();
        }
        else if (s[i] == ')' && st.empty()) {
            return false;
        }
    }
    
    if (!st.empty()) answer = false;

    return answer;
}
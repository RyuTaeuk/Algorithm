#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n = s.size();
    s.insert(s.end(), s.begin(), s.end());
    for(int i=0; i<n; i++) {
        stack<char> st;
        bool isValid = true;
        for(int j=i; j<i+n; j++) {
            if(st.empty() and (s[j] == ')' or s[j] == '}' or s[j] == ']')) {
                isValid = false;
                break;
            }
            if(s[j] == '(' or s[j] == '{' or s[j] == '[')
                st.push(s[j]);
            else if(s[j] == ')' and st.top() != '(') {
                isValid = false;
                break;
            }
            else if(s[j] == '}' and st.top() != '{') {
                isValid = false;
                break;
            }
            else if(s[j] == ']' and st.top() != '[') {
                isValid = false;
                break;
            }
            else
                st.pop();
        }
        if(!st.empty()) isValid = false;
        if(isValid) answer++;
    }
    return answer;
}
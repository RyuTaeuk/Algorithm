#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    while (true) {
        string s;
        getline(cin, s);

        // 종료 조건: 마지막 문자가 '.' 인 경우
        if (s == ".") {
            break;
        }

        stack<char> st;
        bool balanced = true;

        for (char c : s) {
            if (c == '(' || c == '[') {
                st.push(c);
            }
            else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    balanced = false;
                    break;
                }
                st.pop();
            }
            else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    balanced = false;
                    break;
                }
                st.pop();
            }
        }

        if (balanced && st.empty()) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}
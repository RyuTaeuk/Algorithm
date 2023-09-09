#include <iostream>
#include <stack>
using namespace std;

void editor(){
    return;
}

int main(){
    char c;
    string s = "";
    stack<char> st1, st2;
    int m;

    cin >> s;
    cin >> m;

    for (int i = 0; i < s.size(); i++){
        st1.push(s[i]);
    }

    for (int i = 0; i<m; i++){
        cin >> c;
        if(c == 'L'){
            if(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        else if(c == 'D'){
            if(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
        else if(c == 'B'){
            if(!st1.empty()){
                st1.pop();
            }
        }
        else if(c == 'P'){
            cin >> c;
            st1.push(c);
        }
        else break;
    }

    while(!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
    }

    while(!st2.empty()){
        cout << st2.top();
        st2.pop();
    }
    cout << "\n";
}
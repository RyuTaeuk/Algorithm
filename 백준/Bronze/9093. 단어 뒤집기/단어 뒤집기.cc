#include <iostream>
#include <stack>
using namespace std;


int main(){
    int n;
    string s;
    stack<char> st;
    cin >> n;
    cin.ignore();

    for (int i=0; i<n; ++i){
        getline(cin, s);
        s += " ";

        for(int j=0; j<s.size(); ++j){
            if(s[j] == ' ') {
                while(!st.empty()){
                    cout<<st.top();
                    st.pop();
                }
                cout<<" ";
                //스택을 다 비워냄
            }
            else st.push(s[j]);
        }
    }
    cout << "\n";
    return 0;
}
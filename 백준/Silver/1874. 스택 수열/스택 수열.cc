#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    stack<int> st;
    vector<char> v;
    int n, x, tmp = 1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        while (tmp <= x) {
            st.push(tmp);
            v.push_back('+');
            tmp++;
        }
        
        if (st.top() == x) {
            st.pop();
            v.push_back('-');
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }

    return 0;
}
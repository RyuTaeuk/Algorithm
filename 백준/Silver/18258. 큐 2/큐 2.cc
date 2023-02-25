#include <iostream>
#include <string>
using namespace std;

int q[2000000];
int front = 0, back = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n , r, x;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "push") {
            cin >> x;
            q[back++] = x;
        }
        else if (s == "pop") {
            if ((back - front) == 0) cout << -1 << '\n';
            else {
                cout << q[front++] << '\n';
            }
        }
        else if (s == "size") {
            cout << back - front << '\n';
        }
        else if (s == "empty") {
            if ((back - front) == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (s == "front") {
            if ((back - front) != 0) cout << q[front] << '\n';
            else cout << -1 << '\n';
        }
        else if (s == "back") {
            if ((back - front) != 0) cout << q[back - 1] << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int d[20000];
int f = 10000, b = 10000;

int main() {
    int n, tmp;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "push_back") {
            cin >> tmp;
            d[b++] = tmp;
        }
        else if (s == "push_front") {
            cin >> tmp;
            d[--f] = tmp;
        }
        else if (s == "pop_front") {
            if (b - f) cout << d[f++] << '\n';
            else cout << -1 << '\n';
        }
        else if (s == "pop_back") {
            if (b - f) {
                cout << d[b - 1] << '\n';
                b--;
            }
            else cout << -1 << '\n';
        }
        else if (s == "size") {
            cout << b - f << '\n';
        }
        else if (s == "empty") {
            if (b - f) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else if (s == "front") {
            if(b - f) cout << d[f] << '\n';
            else cout << -1 << '\n';
        }
        else if (s == "back") {
            if (b - f) cout << d[b - 1] << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}
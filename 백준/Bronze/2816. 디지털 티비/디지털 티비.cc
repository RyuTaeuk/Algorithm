#include <string>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, kbs1 = -1, kbs2 = -1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s == "KBS1")
            kbs1 = i;
        else if(s == "KBS2") 
            kbs2 = i;
    }

    int inOrder = kbs1 > kbs2 ? 1 : 0;
    for (int i = 0; i < kbs1; i++)
        cout << 1;
    for (int i = 0; i < kbs1; i++)
        cout << 4;
    for (int i = 0; i < kbs2 + inOrder; i++)
        cout << 1;
    for (int i = 0; i < kbs2 + inOrder - 1; i++)
        cout << 4;
    cout << '\n';
    return 0;
}
#include <iostream>
using namespace std;

int n, m;
int result[9] = { 0, };

void searching(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    } // m 사이즈의 수열이 완성되었을때 return

    for (int i = 1; i <= n; i++) {
        result[cnt] = i;
        searching(cnt + 1);

    } //수열을 만드는 과정
}

int main() {
    cin >> n >> m;
    searching(0);

    return 0;
}
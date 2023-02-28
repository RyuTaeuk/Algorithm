#include <iostream>
using namespace std;

int n, m;
bool visited[9] = { false, };
int result[9] = { 0, };

void searching(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) 
            cout << result[i] << ' ';
        cout << '\n';
        return;
    } // m 사이즈의 수열이 완성되었을때 return

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            result[cnt] = i;
            searching(cnt + 1);
            visited[i] = false;
        }
    } //수열을 만드는 과정, 
    //서로 중복되지 않아야 하므로 
    //visited 배열로 사용한 자연수를 표시
}

int main() {
    cin >> n >> m;
    searching(0);

    return 0;
}
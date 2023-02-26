#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    queue<int> q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        if (q.size() == 1) {
            cout << q.front() << '\n';
            q.pop();
        }
        else {
            q.pop(); // 제일 위에 있는 카드를 바닥에 버린다.
            q.push(q.front()); // 그 다음, "을 밑으로 옮긴다.
            q.pop();
        }
    }

    return 0;
}
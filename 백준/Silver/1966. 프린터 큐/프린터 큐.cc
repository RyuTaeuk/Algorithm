#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t, n, m, p, cnt = 1;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> p;
            q.push(make_pair(p, i));
            pq.push(p);
        }

        while (!q.empty()) {
            if (pq.top() == q.front().first) {
                if (q.front().second == m) {
                    cout << cnt << '\n';
                    break;
                }
                pq.pop();
                q.pop();
                cnt++;
                continue;
            }
            q.push(q.front());
            q.pop();
        }
        while (!q.empty()) q.pop();
        while (!pq.empty()) pq.pop();
        cnt = 1;
    }


    return 0;
}
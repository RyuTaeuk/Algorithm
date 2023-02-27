#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    int n, m, tmp, cnt1 = 0, cnt2 = 0, result = 0;
    deque<int> d1, d2;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        d1.push_back(i);
        d2.push_back(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        while (tmp != d1.front()) {
            d1.push_back(d1.front());
            d1.pop_front();
            cnt1++;
        }
        d1.pop_front();

        while (tmp != d2.front()) {
            if (cnt2 >= cnt1) break;
            d2.push_front(d2.back());
            d2.pop_back();
            cnt2++;
        }
        if (cnt2 < cnt1) d2.pop_front();

        if (cnt2 < cnt1) {
            d1 = d2;
            result += cnt2;
        }
        else {
            d2 = d1;
            result += cnt1;
        }
        cnt1 = 0;
        cnt2 = 0;
    }
    cout << result << '\n';

    return 0;
}
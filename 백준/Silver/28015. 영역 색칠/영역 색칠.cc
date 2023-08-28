#include <iostream>
#include <utility>
using namespace std;


int main(void) {
    int n, m, last = 0, cur, cnt = 0;
    int ones = 0, twos = 0;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &cur);
            if (cur == 0) {
                if (last != 0) {
                    cnt += min(ones, twos) + 1;
                    last = 0;
                    ones = 0;
                    twos = 0;
                }
            }
            if (cur == 1) {
                if (last != 1) ones++;
                last = 1;
            }
            if (cur == 2) {
                if (last != 2) twos++;
                last = 2;
            }
        }
        if (ones == 0 && twos == 0) continue;
        cnt += min(ones, twos) + 1;
        last = 0;
        cur = 0;
        ones = 0;
        twos = 0;
    }
    printf("%d\n", cnt);
    return 0;
}
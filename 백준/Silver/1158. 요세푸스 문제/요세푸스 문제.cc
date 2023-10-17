#include <iostream>
#include <utility>
#include <queue>
using namespace std;

void sol(int n, int k) { //using queue
    queue<int> q;
    int result = 0;
    int tmp;
    int i = 1;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    printf("<");
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        if (i % k != 0) q.push(tmp);
        else if (!q.empty()) printf("%d, ", tmp);
        else printf("%d>\n", tmp);
        i++;
    }
    
    return;
}

int main(void) {
    int n, k;
    cin >> n >> k;
    sol(n, k);
    return 0;
}
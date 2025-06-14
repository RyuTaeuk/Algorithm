#include <cstdio>

int main() {
    int h, w, n, m;
    scanf("%d %d %d %d", &h, &w, &n, &m);

    int t1, t2;
    if(h%(n+1)==0){
        t1 = h / (n + 1);
    } else {
        t1 = h / (n + 1) + 1;
    }
    if(w%(m+1)==0){
        t2 = w / (m + 1);
    } else {
        t2 = w / (m + 1) + 1;
    }
    printf("%d\n", t1 * t2);
    return 0;
}
#include <cstdio>

using namespace std;

int main() {
    int a, b, c;
    while(true){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0 && b == 0 && c == 0)
            break;
        if(a + b <= c || a + c <= b || b + c <= a) {
            printf("Invalid\n");
            continue;
        }
        if(a == b && b == c) {
            printf("Equilateral\n");
        } else if(a == b || b == c || a == c) {
            printf("Isosceles\n");
        } else {
            printf("Scalene\n");
        }
    }

    return 0;
}
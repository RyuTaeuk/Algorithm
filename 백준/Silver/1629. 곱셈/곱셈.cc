#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b, int c){
    if(b == 1) return a % c;
    long long result = solution(a, b/2, c);
    result = result * result % c;
    if(b%2 == 0) return result;
    return result * a % c;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << solution(a, b, c) << '\n';

    return 0;
}
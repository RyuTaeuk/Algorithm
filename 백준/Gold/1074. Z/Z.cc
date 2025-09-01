#include <bits/stdc++.h>
using namespace std;

int solution(int n, int r, int c){
    if (n == 0) return 0;

    int half = (1<<n) / 2;

    if(r < half && c < half) // 1분면
        return solution(n-1, r, c);
    else if(r < half && c >= half) //2분면
        return half*half+solution(n-1, r, c-half);
    else if(r >= half && c < half) //3분면
        return half*half*2+solution(n-1, r-half, c);
    else //4분면
        return half*half*3+solution(n-1, r-half, c-half);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    cout << solution(n, r, c) << '\n';
    return 0;
}
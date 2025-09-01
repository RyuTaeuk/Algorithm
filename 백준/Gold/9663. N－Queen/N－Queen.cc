#include <bits/stdc++.h>
using namespace std;


int arr[16];
bool vis1[16], vis2[32], vis3[32];
int n, result=0;
void solution(int cnt){
    if(cnt == n) {
        result++;
        return;
    }

    for(int i=0; i<n; i++){
        if(vis1[i] || vis2[i+cnt] || vis3[cnt-i+n-1])
            continue;
        
        vis1[i] = 1;
        vis2[i+cnt] = 1;
        vis3[cnt-i+n-1] = 1;
        solution(cnt+1);
        vis1[i] = 0;
        vis2[i+cnt] = 0;
        vis3[cnt-i+n-1] = 0;
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solution(0);
    cout << result << '\n';
    return 0;
}
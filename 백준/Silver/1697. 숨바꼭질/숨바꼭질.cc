#include <bits/stdc++.h>
using namespace std;

#define MAX 1000002
int dist[MAX];
int N, K;
int dx[3] = {1, -1, 2};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    fill(dist, dist + MAX, -1);

    queue<int> q;
    dist[N] = 0;
    q.push(N);


    //BFS 시작
    while (!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == K) {
            cout << dist[cur] <<'\n';
            return 0;
        }
        for(int dir=0; dir<3; dir++){
            int nx;
            if(dir == 2) nx = cur * dx[dir];
            else nx = cur + dx[dir];

            if(nx < 0 || nx >= MAX) continue;
            if(dist[nx] >= 0) continue;
            dist[nx] = dist[cur]+ 1;
            q.push({nx});
        }
    }

    return 0;
}
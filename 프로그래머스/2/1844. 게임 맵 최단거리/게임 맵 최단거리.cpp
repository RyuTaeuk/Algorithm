#include<vector>
#include<utility>
#include<queue>
using namespace std;

bool visited[101][101] = {false, };
int dist[101][101] = {0, };

int bfs(vector<vector<int>> maps, int x, int y){
    queue<pair<int, int>> q;
    int n = maps[0].size();
    int m = maps.size();
    int posx[4] = {1, 0, -1, 0};
    int posy[4] = {0, 1, 0, -1};
    
    dist[x][y] = 1;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        
        q.pop();
        
        for(int i=0; i<4; i++){
            int newx = curx + posx[i];
            int newy = cury + posy[i];
            
            if(newx < 0 || newx >= m) continue;
            if(newy < 0 || newy >= n) continue;
            if(visited[newx][newy]) continue;
            if(maps[newx][newy] == 0) continue;
            
            visited[newx][newy] = true;
            q.push(make_pair(newx, newy));
            dist[newx][newy] = dist[curx][cury] + 1;
        }
    }
    
    if (!visited[m-1][n-1]) return -1;
    return dist[m-1][n-1];
}

int solution(vector<vector<int>> maps)
{
    int answer = bfs(maps, 0, 0);
    return answer;
}
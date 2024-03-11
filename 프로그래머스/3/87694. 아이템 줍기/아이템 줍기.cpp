#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[101][101] = {false, };
int map[101][101] = {0, };

void makeMap(vector<vector<int>> rect){
    for(int i = 0; i<rect.size(); i++){
        for(int j = 0; j<rect[0].size(); j++){
            rect[i][j] *= 2;
        }
        int x1 = rect[i][0];
        int x2 = rect[i][2];
        int y1 = rect[i][1];
        int y2 = rect[i][3];
        
        for(int y = y1; y <= y2; y++){
            for(int x = x1; x <= x2; x++){
                map[y][x] = 1;
            }
        }
    }
    for(int i = 0; i<rect.size(); i++){
        int x1 = rect[i][0];
        int x2 = rect[i][2];
        int y1 = rect[i][1];
        int y2 = rect[i][3];
        
        for (int y = y1 + 1; y < y2; y++){
            for (int x = x1 + 1; x < x2; x++){
                map[y][x] = 0;
            }
        }
    }
}

void bfs(int curX, int curY, int itemX, int itemY, vector<vector<int>> rect){
    int posX[4] = {1,0,-1,0};
    int posY[4] = {0,1,0,-1};
    queue<pair<int, int>> q;
    q.emplace(curX, curY);
    while(!q.empty()){
        curX = q.front().first;
        curY = q.front().second;
        q.pop();
        if(curX == itemX && curY == itemY) return;
        
        for(int i = 0; i<4; i++){
            int nextX = curX + posX[i];
            int nextY = curY + posY[i];
            if(map[nextY][nextX] && !visited[nextY][nextX]){
                q.emplace(nextX, nextY);
                visited[nextY][nextX] = true;
                map[nextY][nextX] = map[curY][curX] + 1;
            }
        }
    }
    return;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    characterX *= 2;
    characterY *= 2;
    itemX *=2;
    itemY *=2;
    makeMap(rectangle);
    bfs(characterX, characterY, itemX, itemY, rectangle);
    int answer = map[itemY][itemX] / 2;
    return answer;
}
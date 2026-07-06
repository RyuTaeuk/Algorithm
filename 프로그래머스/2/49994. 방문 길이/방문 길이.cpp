#include <string>
#include <set>
#include <iostream>
using namespace std;
using Path = pair<pair<int, int>, pair<int, int>>;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool inRange(int x, int y){
    return x <= 5 && y <= 5 && x >= -5 && y >= -5;
}

int solution(string dirs) {
    int answer = 0;
    set<Path> s;
    int idx;
    int x=0, y=0;
    for(auto &c : dirs) {
        switch(c) {
            case 'U': idx = 0; break;
            case 'D': idx = 1; break;
            case 'L': idx = 2; break;
            case 'R': idx = 3; break;
            default: idx = -1;
        }
        int nx = x+dx[idx];
        int ny = y+dy[idx];
        if(!inRange(nx, ny)) continue;
        
        s.insert({{x, y}, {nx, ny}});
        s.insert({{nx, ny}, {x, y}});
        
        x = nx;
        y = ny;
    }
    
    answer = s.size() / 2;
    return answer;
}
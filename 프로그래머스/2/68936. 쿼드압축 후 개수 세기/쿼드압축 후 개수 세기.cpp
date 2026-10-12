#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isSame(vector<vector<int>>& arr, int offset_x, int offset_y, int size) {
    if(size == 1) return true;
    
    int ones = 0, zeros = 0;
    for(int i=offset_x; i<offset_x+size; i++) {
        for(int j=offset_y; j<offset_y+size; j++){
            if(arr[i][j] == 1) ones++;
            if(arr[i][j] == 0) zeros++;
            if(ones >= 1 && zeros >= 1) return false;
        }
    }
    
    return true;
}

bool visited[1025][1025] = {false, };
void checkVisit(vector<vector<int>>& arr, int offset_x, int offset_y, int size) {
    for(int i=offset_x; i<offset_x+size; i++) {
        for(int j=offset_y; j<offset_y+size; j++){
            visited[i][j] = true;
        }
    }
    // cout << "print: \n";
    // for(int i=0; i<arr.size(); i++) {
    //     for(int j=0; j<arr.size(); j++){
    //         cout<< visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2);
    int size = arr.size();
    int cnt = 0;
    while(size > 0 && cnt < arr.size() * arr.size()) {
        //세로 오프셋 이동
        for(int x=0; x < arr.size(); x += size) {
            //가로 오프셋 이동
            for(int y=0; y < arr.size(); y += size) {
                //굳이 범위 전체를 visited 처리해줄 필요가 있을까
                //있네
                if(visited[x][y]) continue;
                
                if(isSame(arr, x, y, size)) {
                    answer[arr[x][y]]++;
                    cnt += size*size;
                    checkVisit(arr, x, y, size);
                }
            }
        }
        size /= 2;
    }
    return answer;
}
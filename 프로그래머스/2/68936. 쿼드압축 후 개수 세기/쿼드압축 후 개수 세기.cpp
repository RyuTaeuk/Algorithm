#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer(2);
void solve(vector<vector<int>>& arr, int x, int y, int size) {
    int ones = 0, zeros = 0;
    for(int i=x; i<x+size; i++) {
        for(int j=y; j<y+size; j++){
            if(arr[i][j] == 1) ones++;
            if(arr[i][j] == 0) zeros++;
            if(ones >= 1 && zeros >= 1) {
                int new_size = size/2;
                solve(arr, x, y, new_size);
                solve(arr, x, y+new_size, new_size);
                solve(arr, x+new_size, y, new_size);
                solve(arr, x+new_size, y+new_size, new_size);
                return;
            }
        }
    }
    
    answer[arr[x][y]]++;
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    solve(arr, 0, 0, arr.size());
    return answer;
}
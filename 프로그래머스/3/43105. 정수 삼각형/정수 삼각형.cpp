#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    //각각의 바닥으로 이어지는 경로는 왼쪽 i번과 오른쪽 height-i번의 조합임 hCi
    //h-i번까지의 최댓값을 구하고 거기에 왼쪽오른쪽 값을 더하면될듯
    //0번째와 h번째 바닥원소는 전부 왼쪽, 전부 오른쪽을 선택한경우 1가지밖에 없음
    //hCi = (h-1)Ci + (h-1)C(i-1) 각각의 경우 중 최대값
    vector<vector<int>> sums = triangle;
    int h = triangle.size();
    
    for(int i=1; i<h; i++){
        sums[i][0] = sums[i-1][0] + triangle[i][0];
        sums[i][i] = sums[i-1][i-1] + triangle[i][i];
        
        for(int j=1; j<i; j++){ //i == i번째 바닥 너비
            sums[i][j] = max(sums[i-1][j-1]+triangle[i][j], sums[i-1][j]+triangle[i][j]);
        }
    }
    
    for(int i=0; i<h; i++){
        answer = max(answer, sums[h-1][i]);
    }
    return answer;
}
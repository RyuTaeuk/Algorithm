#include <iostream>
#include <vector>
using namespace std;

//DP임
int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for(int i=1; i<land.size(); i++) {
        int max1 = -1, max2 = -1;
        int max1_idx = -1;
        for(int j=0; j<4; j++) {
            int val = land[i-1][j];
            if(val > max1) {
                max2 = max1;
                max1 = val;
                max1_idx = j;
            }
            else if(val > max2) {
                max2 = val;
            }
        }
        
        for(int j = 0; j<4; j++) {
            if(j == max1_idx) {
                land[i][j] += max2;
            }
            else {
                land[i][j] += max1;
            }
        }
    }
    for(int i=0; i<4; i++) {
        answer = max(answer, land.back()[i]);
    }
    return answer;
}
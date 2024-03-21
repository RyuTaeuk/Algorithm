#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int idx=0, count=0;
    while(idx < progresses.size()){
        for(int i=0; i<progresses.size(); i++){      
            progresses[i] += speeds[i];
        }
        
        for(; idx<progresses.size(); idx++){
            if(progresses[idx] >= 100) count++;
            else break;
        }
        if(count) answer.push_back(count);
        count = 0;
    }
    
    return answer;
}
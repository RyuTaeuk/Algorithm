#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

//메인 컨테이너 벨트 < queue
//보조 컨테이너 벨트 < stack
//4-3-2-5
int solution(vector<int> order) {
    int answer = 0;
    queue<int> mainBelt;
    stack<int> subBelt;
    int idx = 0;
    int cur = 0;
    while(idx < order.size()) {
        if(!subBelt.empty() && subBelt.top() == order[idx]) {
            mainBelt.push(subBelt.top());
            subBelt.pop();
            idx++;
            answer++;
        } else if(cur <= order[idx]) {
            for(; cur < order[idx]; cur++) {
                subBelt.push(cur);
            }
            mainBelt.push(cur);
            cur++;
            idx++;
            answer++;
        } else {
            break;
        }
    }
    return answer;
}
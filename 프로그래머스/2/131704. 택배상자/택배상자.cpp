#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;


//보조 컨테이너 벨트 < stack
//4-3-2-5
int solution(vector<int> order) {
    int answer = 0;

    stack<int> subBelt;
    int idx = 0;
    for (int box = 1; box <= order.size(); box++) {
        subBelt.push(box);
        
        while(!subBelt.empty() && subBelt.top() == order[idx]) {
            subBelt.pop();
            idx++;
            answer++;
        }
    }
    return answer;
}
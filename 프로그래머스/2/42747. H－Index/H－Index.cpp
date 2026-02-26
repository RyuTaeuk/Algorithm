#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    for(int h=0; h<=citations.size(); h++) {
        int cnt = 0;
        for(auto c : citations)
            if(c >= h) cnt++;
        // cnt >= h 이면 최댓값 갱신
        if(cnt >= h) answer = max(answer, h);
    }
    return answer;
}
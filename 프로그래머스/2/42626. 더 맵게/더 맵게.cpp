#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while(pq.top() < K) {
        if(pq.size() < 2) {
            answer = -1;
            break;
        }
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        int new_scoville = num1 + 2 * num2;
        pq.push(new_scoville);
        answer++;
    }
    return answer;
}
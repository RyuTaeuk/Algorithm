#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = 0, sum2 = 0;
    int limit = 4 * queue1.size();
    for(int i=0; i<queue1.size(); i++) {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    queue<int> q1, q2;
    for(int x : queue1) q1.push(x);
    for(int x : queue2) q2.push(x);
    
    while(sum1 != sum2 && answer < limit) {
        if(sum1 > sum2) {
            q2.push(q1.front());
            sum1 -= q1.front();
            sum2 += q1.front();
            q1.pop();
            answer++;
        }
        else if (sum2 > sum1) {
            q1.push(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop();
            answer++;
        }
    }
    
    return sum1 == sum2 ? answer : -1;
}
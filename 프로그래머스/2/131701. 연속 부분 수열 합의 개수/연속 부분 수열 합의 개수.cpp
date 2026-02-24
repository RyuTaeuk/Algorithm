#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

//Prefix Sum 써보기

int solution(vector<int> elements) {
    int n = elements.size();
    // 원형 수열 = 벡터 두배로만들어놔도 풀림
    elements.insert(elements.end(), elements.begin(), elements.end());
    vector<int> sum(2*n);
    
    sum[0] = elements[0];
    for(int i=1; i<2*n; i++)
        sum[i] = sum[i-1] + elements[i];
    
    unordered_set<int> sum_counts;
    for(int l=1; l<=n; l++) { // l = length
        for(int i=0; i<n; i++) {
            // 길이가 l인 부분연속수열의 합 = sum[i+l] - sum[i];
            sum_counts.insert(sum[i+l]-sum[i]);
        }
    }
    
    int answer = sum_counts.size();
    return answer;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long N, total_costs=0;
    
    cin >> N;
    vector<long long> roads(N-1);
    vector<long long> costs(N);
    for(int i=0; i<N-1; i++){
        cin >> roads[i];
    }
    
    for(int i=0; i<N; i++){
        cin >> costs[i];
    }

    //필수조건: 첫 도시에서 두번째 도시 가기
    total_costs += roads[0] * costs[0];

    //이제, 가장 기름값이 싼 도시 찾기.
    int current_min = costs[0];
    for(int i=1; i<N-1; i++){
        if(current_min>costs[i])
            current_min = costs[i];
        total_costs += current_min * roads[i];
    }
    cout << total_costs << '\n';
    return 0;
}
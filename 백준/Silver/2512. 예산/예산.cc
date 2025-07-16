#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N;
    vector<int> budget(N, 0);

    for(int i=0; i<N; i++){
        cin >> budget[i];
    }

    cin >> M;

    sort(budget.begin(), budget.end());

    //이진탐색
    int start=0, end=budget[N-1];
    int result, sum;
    while(start <= end){
        sum=0;
        int mid = (start+end)/2;
        for(auto i : budget){
            sum += min(i, mid);
        }
        if (M >= sum) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << result;
    return 0;
}
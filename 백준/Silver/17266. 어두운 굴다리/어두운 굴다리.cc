#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, x, prev, max_distance;

    cin >> N >> M;
    for (int i=0; i<M; i++){
        cin >> x;
        
        if(i == 0) max_distance = x;
        else max_distance = max(double(max_distance), ceil(double(x - prev)/2));
        prev = x;
    }
    max_distance = max(max_distance, N - x);

    cout << max_distance << '\n';
    return 0;
}
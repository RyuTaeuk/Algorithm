#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p, new_score, result = -1, rank = 1;
    cin >> n >> new_score >> p;
    vector<int> scores(p);

    for(int i=0; i<n; i++){
        cin >> scores[i];
    }

    //P에 여유공간이 있으면 추가해야함
    for(int i=0; i<n; i++){
        if(scores[i] > new_score)
            rank++;
        else if (scores[i] != new_score) {
            result = rank;
            break;
        } 
    }
    if(result == -1 && n<p) { //예외처리
        if(scores[n-1] == new_score) result = rank;
        else result = n+1;
    }

    cout << result << '\n';
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(vector<int> &v1, vector<int> &v2){
    if(v1[1] == v2[1] && v1[2] == v2[2])
        return v1[3] > v2[3];
    else if(v1[1] == v2[1])
        return v1[2] > v2[2];
    else return v1[1] > v2[1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, country;
    cin >> n;
    cin >> k;
    vector<vector<int>> countries(n, vector<int>(4));
    vector<int> ranks(n);
    for (int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            cin >> countries[i][j]; //0: 나라이름 1: 금 2: 은 3: 동
        }
    }

    sort(countries.begin(), countries.end(), compare);

    if(countries[0][0] == k) { //등수세기-1등 예외
        cout << "1\n";
        return 0;
    }
    ranks[0] = 1;
    for (int i=1; i<n; i++){ 
        if(countries[i][0] == k) {
            if(countries[i-1][1] == countries[i][1]
            && countries[i-1][2] == countries[i][2]
            && countries[i-1][3] == countries[i][3]) {
                cout<< ranks[i-1] << '\n';
                break;
            }
            else {
                cout << i+1 << '\n';
                break;
            }
        }
        else {
            if(countries[i-1][1] == countries[i][1]
            && countries[i-1][2] == countries[i][2]
            && countries[i-1][3] == countries[i][3]) {
                ranks[i] = ranks[i-1];
            }
            else {
                ranks[i] = i+1;
            }
        }
    }
    return 0;
}
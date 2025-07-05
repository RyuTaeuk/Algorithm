#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, leftArm = 0, rightArm = 0
    , leftLeg = 0, rightLeg = 0, body = 0;
    pair<int, int> heart = {-1, -1};
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> v[i][j];
            if(heart.first == -1 && v[i][j] == '*') {
                heart = {i+1, j};
            }
        }
    }
    cout << heart.first+1 << ' ' << heart.second+1 << '\n';
    for(int i=heart.second - 1; i<n && v[heart.first][i] == '*'; i--) leftArm++;
    for(int i=heart.second + 1; i<n && v[heart.first][i] == '*'; i++) rightArm++;
    for(int i=heart.first + 1; i<n && v[i][heart.second] == '*'; i++) body++;
    for(int i=heart.first + body + 1; i<n && v[i][heart.second - 1] == '*'; i++) leftLeg++;
    for(int i=heart.first + body + 1; i<n && v[i][heart.second + 1] == '*'; i++) rightLeg++;

    cout << leftArm << ' ' << rightArm << ' ' << body
    << ' ' << leftLeg << ' ' << rightLeg << '\n';

    return 0;
}
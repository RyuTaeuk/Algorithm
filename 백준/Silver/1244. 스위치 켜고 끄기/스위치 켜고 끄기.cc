#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, tmp;
    pair<int, int> people;

    cin >> n;
    vector<int> switches(n);
    for(int i=0; i<n; i++){
        cin >> switches[i];
    }
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> people.first >> tmp;
        people.second = tmp-1;

        if(people.first == 1){
            for(int j=0; j<n; j++){
                if((j+1)%(people.second+1) == 0)
                    switches[j] = !switches[j];
            }
        } else if(people.first == 2){
            for(int j=people.second;
            2*people.second - j >= 0
            && j<n
            && switches[2*people.second - j] == switches[j]; j++){
                // cout << j << ' ' << 2*people.second - j << '\n';
                switches[j] = !switches[j];
                if(j != people.second)
                    switches[2*people.second - j] = !switches[2*people.second - j];
            }
        }
    }

    for(int i=0; i<n; i++) { 
        cout << switches[i] << ' ';
        if ((i+1)%20 == 0) cout << '\n';
    }

    return 0;
}
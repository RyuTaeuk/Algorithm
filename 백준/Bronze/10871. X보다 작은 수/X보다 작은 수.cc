#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, X, tmp;
    cin >> N >> X;
    
    for(int i=0; i<N; i++){
        cin >> tmp;
        if(tmp < X) cout << tmp << ' ';
    }

    cout <<'\n';

    return 0;
}
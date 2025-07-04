#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, cnt=0, capacity;
    char game;
    string s;
    set<string> player;
    cin >> n >> game;
    
    if(game == 'Y') capacity = 1;
    else if(game == 'F') capacity = 2;
    else if(game == 'O') capacity = 3;
    else capacity = -1;

    for (int i=0; i<n; i++){
        cin >> s;
        player.insert(s);
    }

    cout << player.size()/capacity << '\n';

    return 0;
}
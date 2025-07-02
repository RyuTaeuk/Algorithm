#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int alphabet[26] = {0, };
    for (int i=0; i<s.size(); i++){
        alphabet[s[i] - 'a']++;
    }

    for (int i=0; i<26; i++){
        cout << alphabet[i] << ' ';
    }
    cout << '\n';
    return 0;
}
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b){
    if(a.second == b.second) {
        if(a.first.length() == b.first.length())
            return a.first < b.first;
        else
            return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;

    map<string, int> words;
    string word;

    for (int i=0; i<N; i++){
        cin >> word;
        if (word.length() < M)
            continue;
        words[word]++;
    }

    vector<pair<string, int>> words_sort(words.begin(), words.end());
    sort(words_sort.begin(), words_sort.end(), cmp);

    for (const auto& it : words_sort){
        cout << it.first << '\n';
    }

    return 0;
}
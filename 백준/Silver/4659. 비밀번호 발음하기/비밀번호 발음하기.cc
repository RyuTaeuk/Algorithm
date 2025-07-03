#include <iostream>
#include <string>

using namespace std;

bool isVowel (char c){
    if(c == 'a' || c == 'e' || c == 'i'
        || c == 'o' || c == 'u') return true;
    else return false;
}

bool compare(string s){
    bool cond1 = false;
    for(int i=0; i<s.size(); i++){ //조건 1: 모음이 존재?
        if(isVowel(s[i])) {
            cond1 = true;
            break;
        }
    }
    if(!cond1) return false;
    for(int i=2; i<s.size(); i++){ //조건 2: 3연속 자, 모음
        if(isVowel(s[i]) && isVowel(s[i-1]) && isVowel(s[i-2])) return false;
        if(!isVowel(s[i]) && !isVowel(s[i-1]) && !isVowel(s[i-2])) return false;
    }

    for(int i=1; i<s.size(); i++) { //조건 3: 2연속 동일문자
        if(s[i] == s[i-1]) {
            if(s[i] != 'o' && s[i-1] != 'e') return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    while(true){
        cin >> s;
        if(s == "end") break;
        
        if(compare(s)) cout << "<" << s << "> is acceptable.\n";
        else cout << "<" << s << "> is not acceptable.\n";
    }
    return 0;
}
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> map;
    
    
    for(int i=0; i<genres.size(); i++){
        if(map.find(genres[i]) == map.end()) map.insert(make_pair(genres[i], plays[i]));
        else map[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> genrePlays(map.begin(), map.end());
    sort(genrePlays.begin(), genrePlays.end(), cmp);
    
    pair<int, int> maxSong=make_pair(-1,0), secondSong=make_pair(-1,0);
    for(auto i=genrePlays.begin(); i!=genrePlays.end(); i++){
        for(int j=0; j<genres.size(); j++){
            if(genres[j] == i->first) {
                if(maxSong.second < plays[j]) {
                    secondSong = maxSong;
                    maxSong.first = j;
                    maxSong.second = plays[j];
                }
                else if(secondSong.second < plays[j]) {
                    //현재 max값보다는 작지만 second값보다는 큰값을 찾은경우
                    secondSong.first = j;
                    secondSong.second = plays[j];
                }
            }
        }
        answer.push_back(maxSong.first);
        if(secondSong.first != -1) answer.push_back(secondSong.first);
        maxSong = make_pair(-1, 0);
        secondSong = make_pair(-1, 0);
    } 
    
    return answer;
}
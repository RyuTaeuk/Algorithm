#include <iostream>
#include <vector>
#include <map>

/*
TODO: 6명이 들어왔는지 확인
자격미달팀 거르고 점수 계산(4명까지)
동점시 예외처리
*/

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;

        int tmp;
        vector<int> v(1000);
        map<int, int> team_counts;
        for (int j=0; j<n; j++){
            cin >> v[j];
            team_counts[v[j]]++; //6명 들어오는지 확인
        }

        //인원수 비교하고 점수 계산
        int rank = 1;
        map<int, vector<int>> team_ranks;
        for (int j=0; j<n; j++){
            if(team_counts[v[j]] == 6){
                team_ranks[v[j]].push_back(rank);
            }
            else continue; //탈락팀 스킵
            rank++;
        }

        //승자 비교(작은수, 5등선착)
        int winner = -1;
        int winner_score = 2147483647;
        for (const auto& i: team_ranks){
            //1) 최소값 찾기(4명합)
            int cur_score = i.second[0] + i.second[1]
            + i.second[2] + i.second[3];
            if (cur_score < winner_score) {
                winner = i.first;
                winner_score = cur_score;
            } else if (cur_score == winner_score) {
                //2) 동점처리(5등 선착순)
                if(i.second[4] < team_ranks[winner][4]) {
                    winner = i.first;
                    winner_score = cur_score;
                }
            }
        }
        cout << winner << '\n';
    }

    return 0;
}
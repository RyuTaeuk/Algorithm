#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    // 최소 증설 횟수
    // 각 시간에 반납할 서버들을 관리하기
    vector<int> rented_servers(players.size(), 0);
    
    // 현재 서버의 개수
    int cur_server = 0;
    for(int i=0; i < players.size(); i++) {
        // 서버 반납
        cur_server -= rented_servers[i];
        // 이번 시각에 필요한 서버의 수
        // 음.. 이번 시각에 필요한 서버의 수가 지금 서버 수보다 같거나 작으면 고려할 필요 없는듯
        // 반납만 하면 됨
        int next_server = players[i] / m;
        if(next_server > cur_server) {
            int added = next_server - cur_server;
            // 서버 증설
            answer += added;

            // 서버 반납을 언제 해야 하는지 기록
            if(i+k < rented_servers.size())
                rented_servers[i+k] += added;

            cur_server = next_server;
        }
        
    }
    return answer;
}
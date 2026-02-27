#include <string>
#include <vector>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> cache;
    
    if(cacheSize == 0)
        return cities.size() * 5;
    
    for(string &city : cities) {
        for(char &c : city) {
            c = tolower(c);
        } // 소문자 처리
        
        bool flag = false;
        for(auto it = cache.begin(); it != cache.end(); ++it) {
            if(*it == city) { // cache hit
                answer += 1;
                // list 상단으로 올려주기 위한 erase
                // 이 경우 cache에 새로운 값이 추가되지 않음
                flag = true;
                cache.erase(it);
                break;
            }
        }
        
        if(!flag) {// cache miss
            answer += 5;
            // 캐시가 꽉 찼다면
            // 가장 오래된 값을 빼주기
            if(cache.size() == cacheSize)
                cache.pop_back();
        }
        
        cache.push_front(city);
    }
    
    return answer;
}
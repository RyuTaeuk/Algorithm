function solution(arr) {
    let prevarr = arr.slice();
    var answer = 0;
    while(true){
        arr = arr.map(v => {
            if(v >= 50 && v % 2 === 0) {
                v /= 2;
                return v;
            }
            else if(v < 50 && v % 2 === 1) {
                v = v * 2 + 1;
                return v;
            }
        })
        
        if (JSON.stringify(prevarr) === JSON.stringify(arr)) break;
        answer++;
        prevarr = arr.slice();
    }
    answer--;
    return answer;
}
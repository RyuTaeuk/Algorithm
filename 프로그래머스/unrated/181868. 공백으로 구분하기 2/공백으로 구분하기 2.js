function solution(my_string) {
    var answer = [];
    answer = my_string.split(' ');
    answer = answer.filter(char => {
        return char !== "";
    });
    
    console.log(answer);
    return answer;
}
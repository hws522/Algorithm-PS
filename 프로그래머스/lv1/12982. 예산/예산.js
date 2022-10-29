function solution(d, budget) {
    let answer = 0;
    d.sort((a, b) => a - b).forEach(ele => {
        if(budget - ele >= 0) {
            budget -= ele;
            answer++;
        }
    });
    return answer;
}
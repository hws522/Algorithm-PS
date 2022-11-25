function solution(k, score) {
    let answer = [];
    let scoreBox = [];
    score.forEach((ele, idx) => {
        scoreBox.push(ele);
        scoreBox.sort((a, b) => b - a);
        if(scoreBox.length > k) scoreBox.pop();
        answer.push(scoreBox.at(-1));
        
    })
    return answer;
}
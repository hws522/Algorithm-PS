function solution(k, m, score) {
    var answer = 0;
    let scoreSort = score.sort((a, b) => b - a);
    let scoreArr = [];
    for(let i = 0; i < scoreSort.length; i += m) {
      scoreArr.push(scoreSort.slice(i, i + m));
    }
    for(let i = 0; i < scoreArr.length; i++){
        if(scoreArr[i].length === m) answer += scoreArr[i].at(-1) * m
    }
    
    return answer;
}
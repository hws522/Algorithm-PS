function solution(k, tangerine) {
    let result = {};
    tangerine.forEach(ele => {
        if(!result[ele]) result[ele] = 1;
        else result[ele] += 1
    })
    
    const 크기별배열 = Object.entries(result).sort((a, b) => b[1] - a[1]);
    
    let answer = 0;
    for(let i = 0; i < 크기별배열.length; i++){
        if(k - 크기별배열[i][1] <= 0) {
            answer++;
            break;
        } else {
            k -= 크기별배열[i][1];
            answer++;
        }
    }
    
    return answer;
}
function solution(n) {
    let answer = 0;
    for(let i = 1; i <= n; i++) {
        if(n % i === 0) {
            if(i % 2 !== 0) answer++;
        }
    }
    
    return answer;
}
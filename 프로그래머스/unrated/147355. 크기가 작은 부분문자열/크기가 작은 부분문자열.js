function solution(t, p) {
    let answer = 0;  
    let 자리수 = p.length;
    let 기준값 = parseInt(p);
    
    for(let i = 0;i <= t.length; i++){
        if(t.slice(i, i + 자리수).length === 자리수 && parseInt(t.slice(i, i + 자리수)) <= 기준값) answer++;
    }
        
    return answer;
}
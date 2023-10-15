function solution(priorities, location) {
    let answer = 0;
    let 최우선순위 = Math.max(...priorities);
    
    for(;;) {
        const queue = priorities.shift();
        
        if(queue === 최우선순위) {
            answer++;
            if(location === 0) break;
            else 최우선순위 = Math.max(...priorities);
        } else {
            priorities.push(queue);
        }
        location = location === 0 ? priorities.length - 1 : location - 1;        
    }
    
    return answer;
}
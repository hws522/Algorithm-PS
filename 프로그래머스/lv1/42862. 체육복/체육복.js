function solution(n, lost, reserve) {
    let count = 0;
    let total = new Array(n + 1).fill(1);
    
    for(let i = 0; i < lost.length; i++){
        for(let j = 1; j <= n; j++){
            if(j === lost[i]) total[j] -= 1;
        }
    };
    for(let i = 0; i < reserve.length; i++){
        for(let j = 1; j <= n; j++){
            if(j === reserve[i]) total[j] += 1;
        }
    };
    
    total.shift();
    
    for(let i = 0; i < total.length; i++){
        if(total[i] !== 0) count++;
        else {
            if(total[i - 1] === 2) {
                count++;
                total[i - 1]--;
            }
            else if(total[i + 1] === 2) {
                count++;
                total[i + 1]--;
            }
        } 
    };
    
    console.log(total)
    return count;
}
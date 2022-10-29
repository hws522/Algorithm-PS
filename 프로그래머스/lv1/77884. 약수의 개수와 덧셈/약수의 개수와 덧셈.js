function solution(left, right) {
    let answer = 0;
    let numberArr = [];
    for(let i = left; i <= right; i++){
        numberArr.push(i);
    }
    numberArr.forEach(num => {
        let count = 0;
        for(let i = 1; i <= num; i++){
            if(num % i === 0) count++;
        }
        if(count % 2 === 0) answer += num;
        else answer -= num;
    })
    
    return answer;
}
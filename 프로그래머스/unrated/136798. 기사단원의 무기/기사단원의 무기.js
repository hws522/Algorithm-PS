function solution(number, limit, power) {
    let answer = 0;
    let numberArray = new Array(number).fill(0).map((_, idx) => idx + 1);

    for(let i = 0; i < number; i++){
        let count = 0;
        for(let j = 1; j <= Math.sqrt(numberArray[i]); j++){
            if(numberArray[i] % j === 0) {
                count++;
                if (j < Math.sqrt(numberArray[i])) {
                count++;
            }
            }
        }
        if(count > limit) answer += power;
        else answer += count;
    }
    return answer;
}
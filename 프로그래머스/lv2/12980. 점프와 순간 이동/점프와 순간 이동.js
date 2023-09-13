function solution(n)
{
    let answer = 0; 
    
    while(n > 0) {
        if(n % 2 !== 0) {
            n--;
            answer++;
        } else {
            n /= 2;
        }
    }
    
    // console.log(answer)
    return answer;
}

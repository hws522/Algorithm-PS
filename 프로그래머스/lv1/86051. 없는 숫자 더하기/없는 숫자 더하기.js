function solution(numbers) {
    const 모든숫자의합 = 45;
    let 배열합 = numbers.reduce((a, b) => a + b);
    let answer = 모든숫자의합 - 배열합;
    
    
    return answer;
}
function solution(s) {
    let answer = [];
    let 거리배열 = [];
    let 문자배열 = s.split('');
    문자배열.forEach(문자 => {
        if(!거리배열.includes(문자)) answer.push(-1);
        else answer.push(거리배열.length - 거리배열.lastIndexOf(문자));
        거리배열.push(문자);
    })
    
    
    return answer;
}
function solution(n) {
    let answer = 0;
    let n2진수 = n.toString(2).match(/1/g).length;
    for(let i = n + 1; ; i++) {
        if(n2진수 === i.toString(2).match(/1/g).length) {
            answer = i;
            break;
        }
    }
    return answer;
}
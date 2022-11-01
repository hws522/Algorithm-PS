function solution(absolutes, signs) {
    var answer = 0;
    absolutes.forEach((ele, idx) => {
        if(signs[idx]) answer += ele;
        else answer -= ele;
    })
    return answer;
}
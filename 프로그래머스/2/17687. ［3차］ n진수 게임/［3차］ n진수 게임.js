function solution(n, t, m, p) {
    let answer = '';
    let 문자열 = '';
    let cnt = 0;
    
    for(let i = 0; i < t * m; i++) {
        문자열 += i.toString(n);
    }
    
    while (answer.length < t) {
    const s = 문자열.substring(cnt, cnt + m);
    answer += s[p - 1];
    cnt += m;
  }
    
    return answer.toUpperCase();
}
function solution(s) {
    let 변환횟수 = 0;
    let 제거된0갯수 = 0;
    
    while(s.length !== 1) {
        s = s.replace(/0/g, (match) => {
            제거된0갯수 += match.length;
            return '';
        });
        s = s.length.toString(2);
        변환횟수++;
    }
    
    return [변환횟수, 제거된0갯수];
}
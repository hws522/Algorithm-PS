function solution(n) {
    let 삼진법 = n.toString(3);
    let 반전 = 삼진법.split('').reverse().join('');
    let 십진법 = parseInt(반전, 3);
    
    return 십진법;
}
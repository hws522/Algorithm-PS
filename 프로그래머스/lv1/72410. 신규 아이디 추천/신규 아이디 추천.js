function solution(new_id) {
    let 첫번째 = new_id.toLowerCase();
    let 두번째 = 첫번째.replace(/[^a-z0-9-_.]/g, '');
    let 세번째 = 두번째.replace(/[.]{2,}/g, '.');
    let 네번째 = 세번째.replace(/^[.]+|[.]+$/, '');
    let 다섯번째 = 네번째.replace(/^$/, 'a');
    let 여섯번째 = 다섯번째.substring(0, 15).replace(/[.]+$/, '');
    let 일곱번째 = 여섯번째.padEnd(3, 여섯번째.at(-1))
    
   return 일곱번째;
}
function solution(lottos, win_nums) {
    const 등수 = {
        '6': 1,
        '5': 2,
        '4': 3,
        '3': 4,
        '2': 5,
        '1': 6,
        '0': 6
    }
    let 내로또 = lottos.sort((a, b) => b - a);
    let 당첨번호 = win_nums.sort((a, b) => b - a);
    
    let 최저등수 = 당첨번호.filter(ele => 내로또.includes(ele)).length;
    let 최고등수 = 최저등수 + 내로또.filter(ele => ele === 0).length;
    
    return [등수[최고등수], 등수[최저등수]];
}
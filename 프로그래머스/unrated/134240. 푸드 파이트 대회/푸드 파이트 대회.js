function solution(food) {
    let [물, ...음식들] = food;
    let 왼쪽선수 = '';
    let 오른쪽선수 = '';
    
    음식들.forEach((음식갯수, idx) => {
        if(음식갯수 % 2 !== 0) 음식갯수--;
        왼쪽선수 += (idx + 1).toString().repeat(음식갯수 / 2);
    })
    
    오른쪽선수 = 왼쪽선수.split('').reverse().join('');
    
    return `${왼쪽선수}0${오른쪽선수}`;
}
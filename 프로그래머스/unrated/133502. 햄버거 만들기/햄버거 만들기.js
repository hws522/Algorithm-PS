function solution(ingredient) {
    let answer = 0;
    let 햄버거만들기 = [];
    
    ingredient.forEach((ele, idx) => {
        햄버거만들기.push(ele);
        if(햄버거만들기.length >= 4) {
            let last = 햄버거만들기.slice(-4).join('');
            if(last === '1231') {
                answer++;
                for (let j = 0; j < 4; j++) {
                    햄버거만들기.pop();
                }
            }
        }
    })
    
    return answer;
}


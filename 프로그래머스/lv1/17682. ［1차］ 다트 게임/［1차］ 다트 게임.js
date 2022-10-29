function solution(dartResult) {
    let result = [];
    const 정규식 = /\d{1,2}[SDT]{1}[*|#]?/g;
    let 세번의기회 = dartResult.match(정규식);
    
    세번의기회.forEach(기회 => {
        let 결과 = 0;
        let [점수, 보너스, 옵션] = 기회.split(/([SDT]{1})/);
        if(보너스 === 'S') 결과 = 점수 ** 1;
        if(보너스 === 'D') 결과 = 점수 ** 2;
        if(보너스 === 'T') 결과 = 점수 ** 3;
        
        if(옵션 === '*') {
            if(result.length !== 0) result[result.length - 1] *= 2;
            결과 *= 2;
        }
        if(옵션 === '#') 결과 *= -1;
        
        return result.push(결과);
    })
    return result.reduce((a, b) => a + b)
}
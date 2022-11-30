function solution(brown, yellow) {
    let 넓이 = brown + yellow;
    
    for(let 세로 = 3; 세로 <= brown; 세로++) {
        if(넓이 % 세로 === 0){
            let 가로 = 넓이 / 세로;
            
            if( (세로 - 2) * (가로 - 2) === yellow) {
                return [가로, 세로];
            }
        }
    }
}
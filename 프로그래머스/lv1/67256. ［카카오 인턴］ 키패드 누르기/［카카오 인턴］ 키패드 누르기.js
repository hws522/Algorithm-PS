function solution(numbers, hand) {
    var answer = '';
    let 왼손위치 = '*';
    let 오른손위치 = '#';
    let 키패드거리 = {
        1:[0,3], 2:[1,3], 3:[2,3],
        4:[0,2], 5:[1,2], 6:[2,2],
        7:[0,1], 8:[1,1], 9:[2,1],
        '*':[0,0], 0:[1,0], '#':[2,0],
    };
    
    numbers.forEach((number, idx) => {
        if(number === 1 || number === 4 || number === 7) {
            answer += 'L';
            왼손위치 = number;
        }
        else if(number === 3 || number === 6 || number === 9) {
            answer += 'R';
            오른손위치 = number;
        }
        else {
            let 어느손잡이 = hand === 'left' ? 'L' : 'R';
            let 왼손부터의거리 = Math.abs(키패드거리[왼손위치][0] - 키패드거리[number][0]) + Math.abs(키패드거리[왼손위치][1] - 키패드거리[number][1]);
            let 오른손부터의거리 = Math.abs(키패드거리[오른손위치][0] - 키패드거리[number][0]) + Math.abs(키패드거리[오른손위치][1] - 키패드거리[number][1]);
            
            if(왼손부터의거리 === 오른손부터의거리) {
                answer += 어느손잡이;
                어느손잡이 === 'L' ? 왼손위치 = number : 오른손위치 = number;
            }
            else if(왼손부터의거리 < 오른손부터의거리) {
                answer += 'L';
                왼손위치 = number;
            }
            else {
                answer += 'R';
                오른손위치 = number;
            }
        }
        
    })
    return answer;
}
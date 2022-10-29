function solution(n, arr1, arr2) {
    var answer = [];
    let 지도1 = arr1.map(ele => ele.toString(2).padStart(n, '0'));
    let 지도2 = arr2.map(ele => ele.toString(2).padStart(n, '0'));
    
    지도1.forEach((ele, idx) => {
        let result = '';
        let 좌표1 = ele.split('');
        let 좌표2 = 지도2[idx].split('');
        
        좌표1.forEach((el, id) => {
            if(el + 좌표2[id] > 0) result += '#';
            else result += ' ';
        })
        answer.push(result);
    })
    return answer;
}
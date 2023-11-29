function solution(str1, str2) {
    let onlyStr1 = str1.split('').map((ele, idx, arr) => `${arr[idx]}${arr[idx + 1]}`);
    onlyStr1.pop();
    let onlyStr2 = str2.split('').map((ele, idx, arr) => `${arr[idx]}${arr[idx + 1]}`);
    onlyStr2.pop();
    
    onlyStr1 = onlyStr1.filter(ele => (/^[a-zA-Z]*$/).test(ele) === true).map(ele => ele.toLowerCase());
    onlyStr2 = onlyStr2.filter(ele => (/^[a-zA-Z]*$/).test(ele) === true).map(ele => ele.toLowerCase());
    
    let 교집합 = [...new Set(onlyStr1.filter(ele => onlyStr2.includes(ele)))];
    let 합집합 = [...new Set([...onlyStr1, ...onlyStr2])];
    
    let 중복교집합 = [];
    let 중복합집합 = [];
    
    교집합.forEach(ele => {
        let repeatNumber = Math.min(onlyStr1.filter(str1 => str1 === ele).length, onlyStr2.filter(str2 => str2 === ele).length);
        for(let i = 0; i < repeatNumber; i++) 중복교집합.push(ele);
    });
    
    합집합.forEach(ele => {
        let repeatNumber = Math.max(onlyStr1.filter(str1 => str1 === ele).length, onlyStr2.filter(str2 => str2 === ele).length);
        for(let i = 0; i < repeatNumber; i++) 중복합집합.push(ele);
    })
    
    let 자카드유사도 = 중복교집합.length === 0 && 중복합집합.length === 0 ? 1 : 중복교집합.length / 중복합집합.length;
   
    return Math.floor(자카드유사도 * 65536);
}
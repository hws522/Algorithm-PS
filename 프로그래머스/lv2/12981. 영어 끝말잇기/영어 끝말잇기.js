function solution(n, words) {
    let wordsArr = [];
    let 번호 = 0, 차례 = 0;
    
    for(let i = 0; i < words.length; i++){
        if(wordsArr.includes(words[i]) || (wordsArr.length !== 0 && words[i].at(0) !== wordsArr.at(-1)?.slice(-1))) {
            번호 = (i + 1) % n !== 0 ? (i + 1) % n : n;
            차례 = (i + 1) % n !== 0 ? parseInt((i + 1) / n) + 1 : parseInt((i + 1) / n);
            return [번호, 차례];
        } else wordsArr.push(words[i]);
    }
   return [번호, 차례];
}
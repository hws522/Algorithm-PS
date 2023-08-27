function solution(names, yearns, photo) {
    const resultObj = {};
    names.forEach((name, idx) => resultObj[name] = yearns[idx]);
    
    const answer = photo.map(ele => {
        let sum = 0;
        ele.forEach(el => sum += resultObj[el] || 0);
        return sum;
    })
    
    return answer;
}
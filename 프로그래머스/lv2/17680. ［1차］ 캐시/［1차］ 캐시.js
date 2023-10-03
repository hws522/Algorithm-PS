function solution(cacheSize, cities) {
    let answer = 0;
    let cache = [];
    
    if(cacheSize === 0) return 5 * cities.length;
    
    for(let i = 0; i < cities.length; i++) {
        if(cache.findIndex(ele => ele.toLowerCase() === cities[i].toLowerCase()) === -1) {
            if(cache.length >= cacheSize) cache.shift();
            cache.push(cities[i]);
            answer += 5;
        } else {
            cache.splice(cache.findIndex(ele => ele.toLowerCase() === cities[i].toLowerCase()), 1);
            cache.push(cities[i]);
            answer += 1;
        }
    }
    
    return answer;
}
function solution(k, dungeons) {
    let count = 0;
    let 던전확인배열 = dungeons.map(() => false);
    
    function DFS(현재피로도, 던전수) {
        dungeons.forEach((dungeon, idx) => {
            let [최소피로도, 소모피로도] = dungeon;
            if(던전확인배열[idx] === false && 최소피로도 <= 현재피로도) {
                던전확인배열[idx] = true;
                DFS(현재피로도 - 소모피로도, 던전수 + 1);
                던전확인배열[idx] = false;
            }
            count = Math.max(count, 던전수)
        })
    }
    
    DFS(k, 0);
    return count;
}


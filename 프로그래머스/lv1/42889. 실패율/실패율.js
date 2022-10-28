function solution(N, stages) {
    let 결과 = [];
    let 도달하고클리어함 = {};
    let 도달하고클리어못함 = {};
    let 실패율 = {};
    
    for(let i = 1; i <= N; i++) {
        도달하고클리어함[i] = 0;
        도달하고클리어못함[i] = 0;
    };
    
    stages.forEach(stage => {
        if(stage <= N) {
            도달하고클리어못함[stage]++;
            for(let i = 1; i <= stage; i++) 도달하고클리어함[i]++; 
        }
        else for(let i = 1; i <= N; i++) 도달하고클리어함[i]++; 
    });
    
    for(let i = 1; i <= N; i++) {
        if(도달하고클리어못함[i] === 0) 실패율[i] = 0;
        else 실패율[i] = 도달하고클리어못함[i] / 도달하고클리어함[i];
    };
    
    결과 = Object.entries(실패율).sort(([, a], [, b]) => b - a).map(ele => Number(ele[0]));
    
    return 결과;
}
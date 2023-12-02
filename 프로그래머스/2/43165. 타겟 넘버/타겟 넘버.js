function solution(numbers, target) {
    var answer = 0;
    
    DFS(0,0);
    
    function DFS(idx, sum) {
        if(idx === numbers.length) {
            if(sum === target) {
                answer += 1;
            }
            return;
        }
        DFS(idx + 1, sum + numbers[idx]);
        DFS(idx + 1, sum - numbers[idx]);
    }
    
    return answer;
}
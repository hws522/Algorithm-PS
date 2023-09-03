function solution(people, limit) {
    let answer = 0;
    people.sort((a, b) => b - a).forEach((ele, idx, arr) => {
        if(ele + arr.at(-1) > limit){
            answer++;
        }
        else{
            arr.pop();
            answer++;
        }
    })
    return answer;
}
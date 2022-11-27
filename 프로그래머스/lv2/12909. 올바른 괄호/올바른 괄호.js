function solution(s){
    let 괄호 = [];
    s.split('').forEach((ele, idx) => {
        if(ele === '(') 괄호.push(ele);
        else if(ele === ')') {
            if(괄호.length === 0) return false;
            else 괄호.pop();
        }
    })
    return 괄호.length ? false : true;
}
function solution(s)
{
    const stack = [];
    const strArr = s.split('');
    
    for(let i = 0; i < strArr.length; i++){
        if(stack.at(-1) === strArr[i]) stack.pop();
        else stack.push(strArr[i]);
    }
    
    return stack.length ? 0 : 1
}
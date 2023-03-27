function solution(s) {
    let answer = s.split('').map((char, i) => {
    const count = s.slice(0, i).lastIndexOf(char);
    return count < 0 ? count : i - count;
  });
   return answer; 
}
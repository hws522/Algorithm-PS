function solution(s) {
  let answer = [];
  JSON.parse(s.replace(/{/g, '[').replace(/}/g, ']'))
    .sort((a, b) => a.length - b.length)
    .forEach((ele) => {
      if (!answer.length) answer.push(...ele);
      else answer.push(...ele.filter((el) => !answer.includes(el)));
    });

  return answer;
}
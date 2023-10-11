function solution(progresses, speeds) {
  let answer = [];
  let isHundred = progresses;

  while (isHundred.length > 0) {
    let count = 0;
    speeds.forEach((speed, idx, arr) => {
      if (isHundred[idx] < 100) {
        isHundred[idx] += speed;
      }
    });
    while (isHundred[0] >= 100) {
      count++;
      isHundred.shift();
      speeds.shift();
    }
    if (count) answer.push(count);
  }
  return answer;
}
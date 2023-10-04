function solution(clothes) {
  let answer = 1;
  let result = {};

  clothes.forEach((cloth) => {
    let isExist = result.hasOwnProperty(cloth[1]);
    if (isExist) {
      result[cloth[1]]++;
    } else {
      result[cloth[1]] = 1;
    }
  });

  for (const key in result) {
    answer *= result[key] + 1;
  }

  return answer - 1;
}
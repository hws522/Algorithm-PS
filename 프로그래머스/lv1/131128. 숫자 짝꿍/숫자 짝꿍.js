function solution(X, Y) {
  let answer = "";

  X = [...X];
  Y = [...Y];

  for (let i = 0; i < 10; i++) {
    const X_cnt = X.filter((ele) => Number(ele) === i).length;
    const Y_cnt = Y.filter((ele) => Number(ele) === i).length;
		answer += i.toString().repeat(Math.min(X_cnt, Y_cnt));
  }

  if (answer === "") {
    return "-1";
  } else if (answer.match(/[^0]/g) === null) {
    return "0";
  } else {
    return [...answer].sort().reverse().join("");
  }
}
function solution(arr) {
    return arr.reduce((a, b) => (a * b) / 최대공약수(a, b));
}

function 최대공약수(a, b) {
  if (b === 0) return a;
  return 최대공약수(b, a % b);
}
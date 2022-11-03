function solution(반납할병갯수, 콜라갯수, 빈병갯수) {
  let answer = 0;
  while (빈병갯수 >= 반납할병갯수) {
    const 반납못한병갯수 = 빈병갯수 % 반납할병갯수;
    빈병갯수 = Math.floor(빈병갯수 / 반납할병갯수) * 콜라갯수;
    answer += 빈병갯수;
    빈병갯수 += 반납못한병갯수;
  }
  return answer;
}

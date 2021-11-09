/*
입력으로 주어진 종이의 한 변의 길이 N과 각 정사각형칸의 색(하얀색 또는 파란색)이 주어질 때

잘라진 하얀색 색종이와 파란색 색종이의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 전체 종이의 한 변의 길이 N이 주어져 있다. N은 2, 4, 8, 16, 32, 64, 128 중 하나이다. 

색종이의 각 가로줄의 정사각형칸들의 색이 윗줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다. 

하얀색으로 칠해진 칸은 0, 파란색으로 칠해진 칸은 1로 주어지며, 각 숫자 사이에는 빈칸이 하나씩 있다.

출력
첫째 줄에는 잘라진 햐얀색 색종이의 개수를 출력하고, 둘째 줄에는 파란색 색종이의 개수를 출력한다.
*/

const input = require('fs')
  .readFileSync('input.txt')
  .toString()
  .trim()
  .split('\n');

const paperLength = Number(input.shift());
const papers = input.map(ele => ele.split(' ').map(ele => Number(ele)));

const solution = (paperLength, papers) =>{
  let white = 0;
  let blue = 0;

  const divide = (x, y, length) => {
    let count = 0;
    for(let i = x; i < x + length; i++){
      for(let j = y; j < y + length; j++){
        if(papers[i][j]) count++;
      }
    }

    if(!count) white++;
    else if(count === length * length) blue++;
    else{
      divide(x, y, length / 2);
      divide(x, y + length / 2, length / 2);
      divide(x + length / 2, y, length / 2);
      divide(x + length / 2, y + length / 2, length / 2);
    }
  }

  divide(0, 0, paperLength);
  console.log(white);
  console.log(blue);
}

solution(paperLength, papers);
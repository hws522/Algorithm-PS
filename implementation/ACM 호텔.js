const input = require("fs")
.readFileSync("input.txt")
.toString()
.trim()
.split('\n');

const T = Number(input[0]);
// console.log(T);

for(let i = 1; i <= T; i++){
  const [h, w, n] = input[i].split(' ');
  // console.log(`h: ${h}, w: ${w}, n: ${n}`);
  let number = (parseInt(n / h) + 1);
  if(parseInt(n % h) === 0) number = parseInt(n / h);
  let floor = n % h;
  if(floor === 0) floor = Number(h);
  // console.log(`floor: ${floor}, number: ${String(number).padStart(2,'0')}`);
  console.log(floor + String(number).padStart(2, '0'));
}
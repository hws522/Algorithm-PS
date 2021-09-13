const input = require("fs")
.readFileSync("input.txt")
.toString()
.trim()
.split('\n');

input.forEach(ele => {
  let result = ele.split(' ').map(ele => Number(ele));
  result.sort(function(a, b)  {
    if(a > b) return 1;
    if(a === b) return 0;
    if(a < b) return -1;
  });

  if(result[0] === 0) return;
  if(result[0]**2 + result[1]**2 === result[2]**2) console.log('right');
  else console.log('wrong');
  
})
let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();
let num = parseInt(input);

for(let i = 1; i < 10; i++){
    console.log(`${num} * ${i} = ${num * i}`);
}
let fs = require('fs');
let input = fs.readFileSync('input.txt').toString().trim().split(' ');

const [a, b, c, d, e] = input;
console.log((a * a + b * b + c * c + d * d + e * e) % 10)
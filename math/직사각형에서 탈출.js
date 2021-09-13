const input = require("fs")
.readFileSync("input.txt")
.toString()
.trim()
.split(' ')
.map(ele => Number(ele));

const [x, y, w, h] = input;

let resultX = 0, resultY = 0;

if(w - x <= x) resultX = (w - x);
if(w - x > x) resultX = (x);
if(h - y <= y) resultY = (h - y);
if(h - y > y) resultY = (y);

if(resultX > resultY) console.log((resultY));
else console.log((resultX));
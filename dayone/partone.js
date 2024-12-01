import fs from 'node:fs';

let input = fs.readFileSync('./input').toString();
let array = input.split('\n')

let leftArr = array.map(item => item.split('   ')[0]);
let rightArr = array.map(item => item.split('   ')[1]);

leftArr = leftArr.sort((a, b) => a - b);
rightArr = rightArr.sort((a, b) => a - b);

let distance = 0

for(let i = 0; i < array.length; i++) {
    distance += Math.abs(leftArr[i] - rightArr[i]);
}
console.log(distance);
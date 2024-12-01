import fs from 'node:fs';

let input = fs.readFileSync('./input').toString();
let array = input.split('\n')

let leftArr = array.map(item => item.split('   ')[0]);
let rightArr = array.map(item => item.split('   ')[1]);

let distance = 0

for (let i = 0; i < array.length; i++) {
    const current = leftArr[i]
    distance += current * rightArr.filter(item => item === current).length;
}
console.log(distance)
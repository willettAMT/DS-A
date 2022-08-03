/* 

Given a string that represents a Binary Number, write a function that converts this string into a decimal number. DO NOT use the native parseInt() method. 

For example: 

binToDec('0')   -> 0
binToDec('11')  -> 3
binToDec('100') -> 4
binToDec('101') -> 5
binToDec('0101') -> 5

For more information on how to read binary, check out this article: 
https://m.wikihow.com/Read-Binary

*/

function binToDec(binString) {
  //binary conversion algorithm
  //string to number and then split into array -reserve as array
  const binaryArr = binString.split('').map(Number);
  //reverse index (last index is 0 incrementing by each index moving toward the front)
  const reverseArr = Array.from(Array(binaryArr.length).keys()).reverse();
  //power method 2 ^ reverse index array (map to sum array)
  const poweredArr = reverseArr.map((powered) => {
    return Math.pow(2, powered);
  });
  //multiply sum array by string array
  //reduce string array to single value and return
  return binaryArr.reduce(function (acc, curr, i) {
    return acc + curr * poweredArr[i];
  }, 0);
}

/*  Sharon's Solution
function binToDec(binString){
    let index = 0;
    let sum = 0;
    for (let i = binary.length -1; i > -1; i--){
        if (binary[i] == '1'){
            sum += (Math.pow(2, index));
        };
        index++;
    };
    return sum;
};
*/
// function binToDec(binString){
//     return binString.split('').reverse().reduce(function(x, y, i){
//         return (y === '1') ? x + Math.pow(2, i) : x;
//       }, 0);
// }
// console.log(binToDec('0'));//   -> 0
console.log(binToDec('11')); //  -> 3
console.log(binToDec('100')); // -> 4
console.log(binToDec('101')); // -> 5
console.log(binToDec('0101')); // -> 5

module.exports = { binToDec };

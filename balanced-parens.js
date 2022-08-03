/*
 * write a function that takes a string of text and returns true if
 * the parentheses are balanced and false otherwise.
 *
 * Example:
 *   balancedParens('(');  // false
 *   balancedParens('()'); // true
 *   balancedParens(')(');  // false
 *   balancedParens('(())');  // true
 *
 * Step 2:
 *   make your solution work for all types of brackets
 *
 * Example:
 *  balancedParens('[](){}'); // true
 *  balancedParens('[({})]');   // true
 *  balancedParens('[(]{)}'); // false
 *
 * Step 3:
 * ignore non-bracket characters
 * balancedParens(' const wow = { yo: thisIsAwesome() }'); // true
 * balancedParens(' const newton = () => { telescopes.areSicc(); '); // false
 *
 *
 */

const balancedParens = (input) => {
  const matchCache = {};
  const inputArr = input.split('');
  for (let i = 0; i < inputArr.length; i++) {
    if (inputArr[i] === '(') matchCache[i] = inputArr[i];
    if (inputArr[i] === ')') matchCache[i] = inputArr[i];
  }
  // we have an object of keys
};
console.log(balancedParens('(')); //  // false
console.log(balancedParens('()')); // // true
console.log(balancedParens(')(')); //  // false
console.log(balancedParens('(())')); //  // true
module.exports = { balancedParens };

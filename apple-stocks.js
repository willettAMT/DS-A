/*

Consider an array called apple-stock as an argument. This array 
represents the variation of an Apple stock during a single day. 
The values in the array are in chronological order.

ex: [1000, 500, 1500, 2000, 0] --> The stock began at 1000 and closed at 0;
    [1500, 2000, 50, 500, 0]

Write a function called highestProfit that calculates the highest profit 
you can make in the given day by buying and selling a single Apple stock. 
This is comprised of one buy and one sell. Keep your worst case 
time complexity in O(n^2).

Return 0 if no profit is possible OR if input is invalid.

** Extension **
Refactor your function to improve your time complexity to O(n).
Hint: Use pointers to keep track of the indices of max, min to 
calculate profit along the array.

*/

const highestProfit = (apple_stock) => {
  if (!Array.isArray(apple_stock)) return 0;

  let profit = 0;

  let lowPrice = apple_stock[0];

  for (let i = 1; i < apple_stock.length; i++) {
    const highPrice = apple_stock[i];

    if (typeof highPrice !== 'number') return 0;

    if (lowPrice > highPrice) lowPrice = highPrice;
    else profit = Math.max(profit, highPrice - lowPrice);
  }
  return profit;
};
console.log(highestProfit([1000, 500, 1500, 2000, 0]));
console.log(highestProfit([1500, 2000, 50, 500, 0]));
// console.log(highestProfit([0, 200, 1500, 5, 2000]));

module.exports = { highestProfit };

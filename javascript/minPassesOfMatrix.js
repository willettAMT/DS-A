// function minimumPassesOfMatrix(matrix) {
//   const passes = convertNegative(matrix);
//   console.log(passes);
//   const isNegative = containsNegatives(matrix);
//   console.log(isNegative);
//   return isNegative ? passes - 1 : -1;
// }

// function convertNegative(matrix) {
//   let nextPassQueue = getAllPositivePositions(matrix);
//   console.log(nextPassQueue);
//   let passes = 0;

//   while (nextPassQueue.length) {
//     const currentPassQueue = nextPassQueue;
//     console.log(currentPassQueue);
//     console.log(nextPassQueue.pop());
//     nextPassQueue = [];
//     console.log(nextPassQueue);

//     while (currentPassQueue.length) {
//       const poppedFromCurr = currentPassQueue.pop();
//       console.log(poppedFromCurr);
//       const [currRow, currCol] = poppedFromCurr;
//       console.log(currRow, currCol);
//       const adjacentPositions = getAdjacentPositions(currRow, currCol, matrix);
//       console.log(adjacentPositions);

//       for (position of adjacentPositions) {
//         console.log(position);
//         const [row, col] = position;
//         console.log([row, col]);
//         const value = matrix[row][col];
//         if (value < 0) {
//           matrix[row][col] = value * -1;
//           nextPassQueue.unshift([row, col]);
//         }
//       }
//     }
//     passes += 1;
//   }
//   return passes;
// }

// function getAllPositivePositions(matrix) {
//   const positivePositions = [];
//   // console.log(matrix);
//   for (let i = 0; i < matrix.length; i++) {
//     for (let j = 0; j < matrix[i].length; j++) {
//       const value = matrix[i][j];
//       console.log(value);
//       if (value > 0) {
//         positivePositions.push([i, j]);
//       }
//     }
//   }
//   console.log(positivePositions);
//   return positivePositions;
// }

// function getAdjacentPositions(row, col, matrix) {
//   const adjacentPositions = [];
//   console.log(row, col);

//   if (row > 0) adjacentPositions.push([row - 1, col]);
//   if (row < matrix.length - 1) adjacentPositions.push([row + 1, col]);
//   if (col > 0) adjacentPositions.push([row, col - 1]);
//   if (col < matrix.length - 1) adjacentPositions.push([row, col + 1]);
//   console.log(adjacentPositions);
//   return adjacentPositions;
// }

// function containsNegatives(matrix) {
//   console.log(matrix);
//   for (const row of matrix) {
//     console.log(row);
//     for (const value of row) {
//       console.log(value);
//       if (value < 0) return true;
//     }
//   }
//   return false;
// }

// function minimumPassesOfMatrix(matrix) {
//   const passes = convertNegative(matrix);
//   // console.log(passes);
//   const isNegative = containsNegatives(matrix);
//   // console.log(isNegative);
//   return isNegative ? passes - 1 : -1;
// }

// function convertNegative(matrix) {
//   const queue = getAllPositivePositions(matrix);
//   console.log(queue);
//   let passes = 0;

//   while (queue.length) {
//     let currentSize = queue.length;
//     console.log(currentSize);
//     while (currentSize > 0) {
//       const poppedFromCurr = queue.pop();
//       console.log(poppedFromCurr);
//       const [currRow, currCol] = poppedFromCurr;
//       console.log([currCol, currRow]);
//       const adjacentPositions = getAdjacentPositions(currRow, currCol, matrix);
//       console.log(adjacentPositions);
//       for (position of adjacentPositions) {
//         const [row, col] = position;
//         console.log([row, col]);
//         const value = matrix[row][col];
//         console.log(value);
//         if (value < 0) {
//           matrix[row][col] = value * -1;
//           queue.unshift([row, col]);
//           console.log(queue);
//         }
//       }
//       passes += 1;
//       console.log(passes);
//     }
//   }
//   return passes;
// }

// function getAllPositivePositions(matrix) {
//   const positivePositions = [];

//   for (let i = 0; i < matrix.length; i++) {
//     for (let j = 0; j < matrix[i].length; j++) {
//       const value = matrix[i][j];
//       console.log(value);
//       if (value > 0) {
//         positivePositions.push([i, j]);
//       }
//     }
//   }
//   console.log(positivePositions);
//   return positivePositions;
// }

// function getAdjacentPositions(row, col, matrix) {
//   const adjacentPositions = [];

//   if (row > 0) adjacentPositions.push([row - 1, col]);
//   if (row < matrix.length - 1) adjacentPositions.push([row + 1, col]);
//   if (col > 0) adjacentPositions.push([row, col - 1]);
//   if (col < matrix.length - 1) adjacentPositions.push([row, col + 1]);
//   console.log(adjacentPositions);
//   return adjacentPositions;
// }

// function containsNegatives(matrix) {
//   console.log(matrix);
//   for (const row of matrix) {
//     console.log(row);
//     for (const value of row) {
//       console.log(value);
//       if (value < 0) return true;
//     }
//   }
//   return false;
// }

function minimumPassesOfMatrix(matrix) {
  let passes = 0;
  const queue = [];

  // first pass will iterate and push positive integers in the matrix into the queue
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix[i].length; j++) {
      if (matrix[i][j] > 0) queue.push([i, j]);
    }
  }
  // looping through and adding values to check
  let index = 0;
  let passLength = queue.length;

  while (queue.length !== index) {
    const currentElement = queue[index];
    processAdjacentChildren(currentElement, matrix, queue);

    // check if pass is finished while allowing use of a single array as a queue
    if (index === passLength - 1) {
      passLength = queue.length;
      passes++;
      console.log(passes);
    }
    index++;
    console.log(index);
  }

  // recheck matrix for any remaining negative integers
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix[i].length; j++) {
      if (matrix[i][j] > 0) return -1;
      console.log(matrix[i][j]);
    }
  }
  console.log(passes);
  return passes - 1;
}

function processAdjacentChildren(currentElement, matrix, queue) {
  const i = currentElement[0];
  const j = currentElement[1];

  // check children of current element (BFS)
  if (i !== 0 && matrix[i - 1][j] < 0) {
    queue.push([i - 1, j]);
    matrix[i - 1][j] *= -1;
  }
  if (j !== matrix[i].length - 1 && matrix[i][j + 1] < 0) {
    queue.push([i, j + 1]);
    matrix[i][j + 1] *= -1;
  }
  if (i !== matrix.length - 1 && matrix[i + 1][j] < 0) {
    queue.push([i + 1, j]);
    matrix[i + 1][j] *= -1;
  }
  if (j !== 0 && matrix[i][j - 1] < 0) {
    queue.push([i, j - 1]);
    matrix[i][j - 1] *= -1;
  }
}

console.log(
  minimumPassesOfMatrix([
    [0, -1, -3, 2, 0],
    [1, -2, -5, -1, -3],
    [3, 0, 0, -4, -1],
  ])
);

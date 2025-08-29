function boggleBoard(board, words) {
  const trie = new Trie();
  for (let word of words) {
    console.log(words);
    trie.add(word);
  }
  // console.log(trie)
  const finalWords = {};
  const visited = new Array(board.length).fill(
    new Array(board[0].length).fill(false)
  );
  console.log(visited);
  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[i].length; j++) {
      explore(i, j, board, trie.root, visited, finalWords);
    }
  }
  console.log(trie.root);
  return Object.keys(finalWords);
}

function explore(i, j, board, trieNode, visited, finalWords) {
  // console.log(visited[i][j])
  if (visited[i][j]) return;
  const letter = board[i][j];
  console.log(trieNode[letter]);
  console.log(letter);
  if (!trieNode[letter]) return;
  visited[i][j] = true;
  trieNode = trieNode[letter];
  if (trieNode['*']) {
    finalWords[trieNode['*']] = true;
  }

  const neighbors = getNeighbors(i, j, board);
  for (const neighbor of neighbors) {
    explore(neighbor[0], neighbor[1], board, trieNode, visited, finalWords);
  }
  visited[i][j] = false;
}

function getNeighbors(i, j, board) {
  const neighbors = [];

  if (i > 0 && j > 0) neighbors.push([i - 1, j - 1]);
  if (i > 0 && j < board[0].length - 1) neighbors.push([i - 1, j + 1]);
  if (i < board.length - 1 && j < board[0].length - 1)
    neighbors.push([i + 1, j + 1]);
  if (i < board.length - 1 && j > 0) neighbors.push([i + 1, j - 1]);
  if (i > 0) neighbors.push([i - 1, j]);
  if (i < board.length - 1) neighbors.push([i + 1, j]);
  if (j > 0) neighbors.push([i, j - 1]);
  if (j < board[0].length - 1) neighbors.push([i, j + 1]);

  return neighbors;
}

class Trie {
  constructor() {
    this.root = {};
    this.endSymbol = '*';
  }
  add(word) {
    let current = this.root;
    console.log(word);
    for (let i = 0; i < word.length; i++) {
      console.log(word[i]);
      if (!current[word[i]]) {
        current[word[i]] = {};
        console.log(current);
      }
      current = current[word[i]];
    }
    current[this.endSymbol] = word;
  }
}
const board = [
  ['t', 'h', 'i', 's', 'i', 's', 'a'],
  ['s', 'i', 'm', 'p', 'l', 'e', 'x'],
  ['b', 'x', 'x', 'x', 'x', 'e', 'b'],
  ['x', 'o', 'g', 'g', 'l', 'x', 'o'],
  ['x', 'x', 'x', 'D', 'T', 'r', 'a'],
  ['R', 'E', 'P', 'E', 'A', 'd', 'x'],
  ['x', 'x', 'x', 'x', 'x', 'x', 'x'],
  ['N', 'O', 'T', 'R', 'E', '-', 'P'],
  ['x', 'x', 'D', 'E', 'T', 'A', 'E'],
];

const words = [
  'this',
  'is',
  'not',
  'a',
  'simple',
  'boggle',
  'board',
  'test',
  'REPEATED',
  'NOTRE-PEATED',
];

console.log(boggleBoard(board, words));

// Do not edit the line below.
// exports.boggleBoard = boggleBoard;

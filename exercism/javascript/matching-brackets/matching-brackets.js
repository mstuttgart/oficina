//
// This is only a SKELETON file for the 'Matching Brackets' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

const SYMBOLS = ['[', ']', '{', '}', '(', ')']

export const isPaired = (str) => {

  // Array of symbols find in string
  const stack = []

  for (let c of str) {
    if (SYMBOLS.includes(c)) {
      stack.push(c)
    }
  }

  // empty string
  if (stack.length === 0)
    return true

  // first element of array
  if (stack[0] === ']' || stack[0] === '}' || stack[0] === ']')
    return false

  // last element of array
  if (stack[stack.length - 1] === '[' || stack[stack.length - 1] === '{' || stack[stack.length - 1] === '(')
    return false

  let openSymbol = []

  for (let c of stack) {

    if (c === '[' || c === '{' || c === '(') {
      // mark symbol to close
      openSymbol.push(c)
    } else {

      let last = openSymbol[openSymbol.length - 1]

      if ((c === ']' && last !== '[') || (c === '}' && last !== '{') || (c === ')' && last !== '(')) {
        return false
      } else {
        // Remove de pair symbol
        openSymbol.pop()
      }

    }

  }

  return true

};

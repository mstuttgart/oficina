let isAtivo = true

console.log(isAtivo)

isAtivo = 1
console.log(!!isAtivo) // negacao da negacao


// true

console.log(!![]) // difente do python, aqui é true
console.log(!!{}) // difente do python, aqui é true
console.log(!!Infinity)
console.log(!!' ')

console.log(!!(isAtivo = true)) // resultado da atribuicao e true

// false

console.log(!!0)
console.log(!!'')
console.log(!!null)
console.log(!!NaN)
console.log(!!undefined)

console.log(!!(isAtivo = false)) // resultado da atribuicao e false

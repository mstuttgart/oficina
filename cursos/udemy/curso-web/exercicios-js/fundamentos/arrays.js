const valores = [7.7, 8.9, 6.3, 9.2]

console.log(valores[4])

valores[4] = 10

//  Agora nao da erro
console.log(valores[4])

// Adicionamos 6 itens, sendo o ultimo com valor 5
valores[10] = 5

console.log(valores)

// Tamanho do array
console.log(valores.length)

// Adiciona elemento
valores.push('teste')

console.log(valores)

// Remove elemento
console.log(valores.pop())

// Remove elemento com indice
delete valores[0]

console.log(valores)
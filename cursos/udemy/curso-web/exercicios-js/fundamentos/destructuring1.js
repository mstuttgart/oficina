const pessoa = {
    nome: 'Lara',
    idade: 23,
    endereco: {
        logradouro: 'Rua ABC',
        numero: 123
    }
}

const { nome, idade } = pessoa

console.log(nome, idade)
console.log(pessoa)

const { nome: n, idade: i } = pessoa

console.log(n, i)

const { endereco: { logradouro, numero, cep } } = pessoa

console.log(logradouro, numero, cep)
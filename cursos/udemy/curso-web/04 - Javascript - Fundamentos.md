# Javascript - Fundamentos

Javascript é uma linguagem de auto nível que segue o padrão ECMAScript. Ela é fracamente tipada e possui tipagem dinâmica, Orientação Objetos baseada em Protótipos e funções como cidadão de primeira classe. Suporta os paradigmas de programação imperativo, funcional e orientada a eventos.

## Características

### Fracamente Tipada

Uma linguagem **fracamente tipada** aceita que valores de tipos diferentes sejam atribuídos a uma mesma variável.

```javascript
var a = 'exemplo'

a = 10 // não causa erro
```

Em linguagens **fortemente tipadas** (como C, C++ e Java), ocorreria um erro no codigo acima. Pois um variável que foi declarada com *string*, seria permitido receber apenas valores do tipo *string*.

### Tipagem Dinâmica

Uma linguagem pode possuir tipagem *Estática* ou *Dinâmica*.

Na **Tipagem Estática**, quando o tipo da valores que a variável irá receber é determinado na declaração da variável (como ocorre no C, C++ e Java).

Na **Tipagem Dinâmica**, o tipo de valor da variável é determinado somente no momento que um valor é atribuído a ela.

Podemos usar o comando *typeof* para determinar o tipo do valor contido na variável.

> typeof value

Exemplo:

```javascript
var a = 'exemplo'
typeof a    // string

a = 10
typeof a    // number
```

## Number [^number]

### Sobre

Em Javascript, o tipo **Number** é uma função e representa tanto números inteiros (Integer) como números de ponto flutuante (Float). Ele apresenta várias operações muito úteis, como no exemplo a seguir.

Exemplo:

```javascript
// Exemplo de Numbers
typeof -5    // number
typeof 10    // number
typeof 2.5   // number

// Determinar se um numero é ou não inteiro
Number.isInteger(2.6)   // true
Number.isInteger(15)    // false

// Delimitar o numero de casas decimais
(3.1415).toFixed(2)    // '3.14' 

// Converter valor numerico para string
(3.1415).toString()    // '3.1415'

// Converter valor numerico para string, mas para base binária (2)
(7).toString(2)    // '111'
```

### Operações aritméticas

O Javascript apresenta alguma excentricidades em relação ao *Number* que devem ser observadas.

#### Divisão por zero

Diferente de outras linguagens, o Javascript não irá acusar erro ou disparar uma exceção quando ocorrer uma divisão por zero. Ao invés disso, a linguagem possui o tipo **Infinity**, um tipo especial para representar valores infinitos.

```javascript
a = 5/8   // Infinity
```

#### Operações com tipos diferentes

Por ser fracamente tipada, o Javascript permite alguns tipos de operações envolvendo valores de tipos diferentes.

```javascript
a = '10' / 2    // 5
b = '10' * 2    // 10

c = '10,2' * 2    // Nan (indefinido, por causa da virgula, o JS nao sabe que é um número)
```

#### Chamando funções diretamente

Quando desejado podemos chamar as funções diretamente pelo Number, sem precisar guardar o valor em uma variável primeiro.

```javascript
10.toString()    // Uncaught SyntaxError: Invalid or unexpected token

(10).toString()    // '10'
```

#### Operações com números de ponto flutuante

Em operações com números de ponto flutuante, o Javascript sempre irá retornar o número máximo de casas decimais, seguindo o padrão IEEE [^IEEE].

```javascript
var soma = 0.1 + 0.7    //0.7999999999999999
```

### Math [^math]

O objeto **Math** nos permite executar tarefas matemáticas, como raiz quadrada, elevar um número a determinada potência, seno e cosseno de um determinado angulo e determinar o máximo e mínimo de um determinado conjunto de valores, entre outras funções. 

**Math** não é um construtor, então todos os metodos do objeto podem ser chamados sem criá-lo (semelhante a funções estática de outras linguagens).

```javascript
Math.PI    // valor PI

Math.sqrt(4)    // raiz quadrada de 4.

Math.pow(2, 3)    // 2^3

Math.max(2, 1, 5, 4)    // maior valor de um conjunto de valores
```

## String [^string]

Em Javascript, uma *string* pode ser representada tanto por aspas duplas quanto por aspas simples. A *string*  é tratada como uma lista, isso nos permite realizar buscas e cortes na mesma, conforme a necessidade.

```javascript
text = 'Javascript'

// Retorna o caracter de uma determinada posicao
text.charAt(0)    // 'J'
text.charAt(20)    // '' . string vazia quando o indice nao existir na string

// Retorna o indice de um determinado caracter
text.indexOf('c')    // 5 
text.indexOf('a')    // 1 retorna a primeira ocorrencia do caracter 'a'

// Retorna substring a partir de um intervalor de indices
text.substring(1)    // 'avascript' . Do indice 1 até o final da string
text.substring(0, 3)    // 'Java'. Do indice 0 ao 3

// Concatena strings
text.cocat(' é ', ' nota', ' 10!')    // 'Javascript é nota 10!'

// Separa uma string a partir de um caracter delimitador
'Javascript, Python, Go'.split(',')    // ['Javascript', 'Python', 'Go']

// Busca dentro da string (pode ser utilizado Regex)
'Javascript, Python, Go'.search('Python')    // 12. Indice da primeira ocorrencia que coincide coma busca
```


## Referências

[^number]: https://www.w3schools.com/jsref/jsref_obj_number.asp
[^math]: https://www.w3schools.com/jsref/jsref_obj_math.asp
[^IEEE]: https://en.wikipedia.org/wiki/IEEE_754
[^string]: https://www.w3schools.com/jsref/jsref_obj_string.asp

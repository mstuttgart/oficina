

const calcularBtn = document.getElementById('calcular');


function calcularIMC() {

    const nome = document.getElementById('nome').value;
    const altura = document.getElementById('altura').value;
    const peso = document.getElementById('peso').value;

    const resultado = document.getElementById('resultado');

    if (nome !== '' && altura !== '' && peso !== '') {

        // Arredonda numero de casas decimais para 1
        let valorIMC = (peso / (altura * altura)).toFixed(1);

        let classificacao = '';

        if (valorIMC < 18.5){
            classificacao = 'abaixo do peso';

        }else if (valorIMC < 25){
            classificacao = 'com peso ideal. Parabéns!!!';

        }else if (valorIMC < 30){
            classficacao = 'levemente acima do peso.';

        }else if (valorIMC < 35){
            classificacao = 'com obesidade grau I.';

        }else if (valorIMC < 40){
            classificacao = 'com obesidade grau II.';

        }else {
            classificacao = 'com obesidade grau III. Cuidado!!';
        }

        resultado.textContent = `${nome} seu IMC é ${valorIMC} e você esta ${classificacao}`;

    }else{
        resultado.textContent = 'Preencha todos os campos!';
    }

}

calcularBtn.addEventListener('click', calcularIMC);

module.exports = calcularIMC;

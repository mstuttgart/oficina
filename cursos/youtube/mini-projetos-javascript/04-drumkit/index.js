'use strict';

const sons = {
    'A': 'boom.wav',
    'S': 'clap.wav',
    'D': 'hihat.wav',
    'F': 'kick.wav',
    'G': 'openhat.wav',
    'H': 'ride.wav',
    'J': 'snare.wav',
    'K': 'tink.wav',
    'L': 'tom.wav'
}

const criarDiv = (texto) => {
    const div = document.createElement('div');

    div.classList.add('key');
    div.textContent = texto;
    div.id = texto;

    document.getElementById('container').appendChild(div);
}

const exibir = (sons) => Object.keys(sons).forEach(criarDiv);

const tocarSom = (letra) => {
    const audio = new Audio(`./sounds/${sons[letra]}`);
    audio.play();
}

const adicionarEfeito = (letra) => document.getElementById(letra)
    .classList.toggle('active');

const removerEfeito = (letra) => {
    const div = document.getElementById(letra)
    div.addEventListener('transitionend', () => div.classList.remove('active'));
};

// O 'evento' corresponde ao elemento 'container'
// onde o listener esta atrelado
const ativarDiv = (evento) => {

    const letra = evento.type == 'click' ? evento.target.id : evento.key.toUpperCase();

    if (sons.hasOwnProperty(letra)) {
        adicionarEfeito(letra);
        tocarSom(letra);
        removerEfeito(letra);
    }

}

document.getElementById('container')
    .addEventListener('click', ativarDiv);

// Evento de tecla
window.addEventListener('keyup', ativarDiv);


exibir(sons);

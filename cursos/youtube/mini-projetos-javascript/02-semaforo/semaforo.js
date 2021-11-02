
const btnDesligar = document.getElementById('desligado');

const btnRed = document.getElementById('red');
const btnYellow = document.getElementById('yellow');
const btnGreen = document.getElementById('green');

const btnAutomatico = document.getElementById('automatic');

const semaforoImg = document.getElementById('semaforo_img');

let intervalID;
let currentColor;

const colors = {
    'red': () => semaforoImg.src = './img/vermelho.png',
    'yellow': () => semaforoImg.src = './img/amarelo.png',
    'green': () => semaforoImg.src = './img/verde.png',
    'off': () => semaforoImg.src = './img/desligado.png',
}

function loopColor () {
    
    switch( currentColor ) {
        
        case 'red':
            currentColor = 'yellow';
            break;
            
        case 'yellow':
            currentColor = 'green';
            break;

        case 'green':
            currentColor = 'red';
            break;
            
        default:
            currentColor = 'red';            

    };
    
    colors[currentColor]();

}


btnDesligar.addEventListener('click', () => {

    // 'Desligamos' o semaforo
    colors['off']();
    currentColor = 'off';
    
    // Encerramos a thread responsavel pelo timer
    if ( intervalID ) {
        clearInterval(intervalID);
        intervalID = 0;
    }

});

btnRed.addEventListener('click', () => {
    
    if ( ! intervalID ) {
        colors['red']();
    }
});

btnYellow.addEventListener('click', () => {
          
    if ( ! intervalID ) {
        colors['yellow']();
    }
  
});

btnGreen.addEventListener('click', () => {

    if ( ! intervalID ) {
        colors['green']();
    }

});

btnAutomatico.addEventListener('click', () => {

    if ( !intervalID ) {
        // Sempre precisamos guardar o ID do timer
        // para que possamos manipula-lo depois
        intervalID = setInterval(loopColor, 1000);    
    }

});



// Define que o javascript sera usado em 'strict' mode
// You can use strict mode in all your programs. It helps you to write cleaner code, like preventing you from using undeclared variables.
// Mais detalhes em: https://developer.mozilla.org/pt-BR/docs/Web/JavaScript/Reference/Strict_mode
'use strict';

// Usamos a hashtag porque a class esta no HTML
const containerItems = document.querySelector('#container-items');

const loadImages = ( container ) => {

    let images = [
        { 'url': 'img/chrono.jpg' },
        { 'url': 'img/inuyasha.jpg' },
        { 'url': 'img/ippo.png' },
        { 'url': 'img/tenchi.jpg' },
        { 'url': 'img/tenjhotenge.jpg' },
        { 'url': 'img/yuyuhakusho.jpg' },                    
    ]
    
    images.forEach( image => {
        
        // Concatena elementos img. Como estamos usando a class, as imagens ja ficam todas com o mesmo tamanho
        container.innerHTML += `
            <div class='item'>
                <img src='${image.url}'/>
            </div>
        `
    
    });

}


// Invocamos a funcao que monta o container de imagens
loadImages( containerItems );

// Aqui, procuramos diretamente pela class CSS .item
let items = document.querySelectorAll('.item');

const previous = () => {

    // Adicionamos o primeiro item no fim do container
    containerItems.appendChild(items[0]);
    
    // Atualizamos a lista de items
    items = document.querySelectorAll('.item');    
}

const next = () => {

    // Pegamos o ultimo item
    const lastItem = items[items.length - 1];
    
    // Inserimos o primeiro item antes do ultimo, 
    // dando a impressao de que o slide voltou ao primeiro item
    containerItems.insertBefore(lastItem, items[0]);
    
    // Atualizamos a lista de items
    items = document.querySelectorAll('.item');
}

document.querySelector('#previous').addEventListener('click', previous);
document.querySelector('#next').addEventListener('click', next);


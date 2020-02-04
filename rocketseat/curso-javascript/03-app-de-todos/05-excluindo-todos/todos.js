var listElement = document.querySelector('#app ul');
var inputElement = document.querySelector('#app input');
var buttonElement = document.querySelector('#app button');

todos = [
    'Fazer café',
    'Estudar Javascript'
];

function renderTodos() {

    //Limpa conteudo HTML da lista
    // de modo a sempre inserirmos itens novos
    listElement.innerHTML = '';

    for (todo of todos) {
        var todoElement = document.createElement('li');
        var todoText = document.createTextNode(todo);

        var linkElement = document.createElement('a');
        var linkText = document.createTextNode('Excluir');

        var pos = todos.indexOf(todo);

        // Define atributo para a tag <a>
        linkElement.setAttribute('href', '#');

        // Grava a funcao com a posicao
        // Inspecionar o elemento <a> no navegador para mais detalhes        
        linkElement.setAttribute('onclick', `deleteTodo(${pos})`);

        linkElement.appendChild(linkText);

        todoElement.appendChild(todoText);
        listElement.appendChild(todoElement);
        listElement.appendChild(linkElement);
    }
}

renderTodos();

function addTodos() {
    var todoText = inputElement.value;
    inputElement.value = '';

    // Adiciona um novo elemento a lista
    todos.push(todoText);
    renderTodos();
}

buttonElement.onclick = addTodos;

function deleteTodo(pos) {
    // Remove a quantidade de elementos definida a 
    // partir da posicao 'pos'
    todos.splice(pos, 1);
    renderTodos();
}



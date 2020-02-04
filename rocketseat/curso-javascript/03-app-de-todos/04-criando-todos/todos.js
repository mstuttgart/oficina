var listElement = document.querySelector('#app ul');
var inputElement = document.querySelector('#app input');
var buttonElement = document.querySelector('#app button');

var todos = [
    'Fazer café',
    'Estudar Javascript'
];

function renderTodos() {

    // Apaga todo o conteudo do HTML
    listElement.innerHTML = '';

    for (todo of todos) {
        var todoElement = document.createElement('li');
        var todoText = document.createTextNode(todo);

        todoElement.appendChild(todoText);
        listElement.appendChild(todoElement);
    }
}

renderTodos();

function addTodos() {

    var todoText = inputElement.value;
    inputElement.value = '';

    todos.push(todoText);
    renderTodos();
}

buttonElement.onclick = addTodos;
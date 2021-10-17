var listElement = document.querySelector('#app ul');
var inputElement = document.querySelector('#app input');
var buttonElement = document.querySelector('#app button');

todos = JSON.parse(localStorage.getItem('list_todos')) || [];


function renderTodos() {

	listElement.innerHTML = '';

	for (todo of todos) {
		var todoElement = document.createElement('li');
		var todoText = document.createTextNode(todo);

		linkElement = document.createElement('a');
		linkText = document.createTextNode('Excluir');

		var pos = todos.indexOf(todo);

		linkElement.setAttribute('href', '#');
		linkElement.setAttribute('onclick', `removeTodo(${pos})`);

		linkElement.appendChild(linkText);

		todoElement.appendChild(todoText);
		listElement.appendChild(todoElement);
		listElement.appendChild(linkElement);
	}
}

renderTodos();

function addTodo() {

	var todoText = inputElement.value;
	inputElement.value = '';

	todos.push(todoText);
	renderTodos();
	saveToStorage();
}


buttonElement.onclick = addTodo;

function removeTodo(pos) {
	todos.splice(pos, 1);
	renderTodos();
	saveToStorage();
}


function saveToStorage() {
	localStorage.setItem('list_todos', JSON.stringify(todos));
}

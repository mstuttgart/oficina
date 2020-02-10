var inputElement = document.querySelector('#app input');
var ulElement = document.querySelector('#app ul');


function adicionar() {

    axios.get(`https://api.github.com/users/${inputElement.value}/repos`)
        .then(function (response) {

            // Limpa lista
            ulElement.innerHTML = '';

            for (repo of response.data) {
                var liElement = document.createElement('li');
                var liText = document.createTextNode(repo.name);

                liElement.appendChild(liText);
                ulElement.appendChild(liElement);
            }

        })
        .catch(function (reject) {
            alert('Usuario não encontrado');
        });

}

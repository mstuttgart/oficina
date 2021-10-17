var inputElement = document.querySelector('#app input');
var ulElement = document.querySelector('#app ul');


function adicionar() {

    ulElement.innerHTML = '';

    var ilElement = document.createElement('li');
    var ilText = document.createTextNode('Carregando...');

    ilElement.appendChild(ilText);
    ulElement.appendChild(ilElement);

    axios.get(`https://api.github.com/users/${inputElement.value}/repos`)
        .then(function (response) {

            ulElement.innerHTML = '';

            for (repo of response.data) {
                var ilElement = document.createElement('li');
                var ilText = document.createTextNode(repo.name);

                ilElement.appendChild(ilText);
                ulElement.appendChild(ilElement);
            }

        })
        .catch(function (reject) {
            alert(reject);
        })

}

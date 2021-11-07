const btnBuscaCEP = document.getElementById('buscar_cep');

function buscaCEP() {

    cep = document.getElementById('cep').value;

    fetch(`https://viacep.com.br/ws/${cep}/json/unicode/`)
    .then(response => response.json())
    .then(response_json => {
        document.getElementById('logradouro').value = response_json.logradouro;
        document.getElementById('complemento').value = response_json.complemento;
        document.getElementById('bairro').value = response_json.bairro;
        document.getElementById('cidade').value = response_json.localidade;
        document.getElementById('uf').value = response_json.uf;
    })
    .catch(err => {
        console.log('Erro de consulta de cep');
    });
    
}

btnBuscaCEP.addEventListener('click', buscaCEP);

var xhr = new XMLHttpRequest();

xhr.open('GET', 'https://api.github.com/users/mstuttgart');
xhr.send(null);

xhr.onreadystatechange = function(){
    // Codigo de quando a resposta esta pronta
    if(xhr.readyState === 4){
        // Transforma resposta em JSON
        console.log(JSON.parse(xhr.responseText));    
    }
}

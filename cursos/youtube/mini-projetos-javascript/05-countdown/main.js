'use strict';

const tagContadorSegundos = document.getElementById('segundos');
const tagContadorMinutos = document.getElementById('minutos');
const tagContadorHoras = document.getElementById('horas');
const tagContadorDias = document.getElementById('dias');

const contadorSegundo = () => {
    let seg = Number(tagContadorSegundos.textContent);
    let min = Number(tagContadorMinutos.textContent);
    let horas = Number(tagContadorHoras.textContent);
    let dias = Number(tagContadorDias.textContent);

    if (seg == 0) {
        seg = 59;

        if (min == 0) {
            min = 59;

            if (horas == 0) {
                horas = 23;
                dias -= 1;
            } else {
                horas -= 1;
            }

        }
        else {
            min -= 1;
        }

    } else {
        seg -= 1;
    }

    tagContadorSegundos.textContent = `${seg}`.padStart(2, '0');
    tagContadorMinutos.textContent = `${min}`.padStart(2, '0');
    tagContadorHoras.textContent = `${horas}`.padStart(2, '0');
    tagContadorDias.textContent = `${dias}`.padStart(2, '0');

}

//  Em segundos
setInterval(contadorSegundo, 1000);

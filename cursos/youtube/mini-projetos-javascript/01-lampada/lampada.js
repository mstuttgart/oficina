const lampadaImg = document.getElementById('lamp');
const buttonOnOff = document.getElementById('buttonOnOff');

// Indica status da lampada. true -> quebrada, false -> nao quebrada
let isLampBroken = false;

// Indica se a lampada esta ou nao ligada
let isLampOn = false;

function turnOnOffLamp () {

	// So e possivel ligar/desligar a lampada se a mesma
	// nao estiver quebrada
	if ( !isLampBroken ) {

		// Ligando a lampada
		if ( !isLampOn ) {

			lampadaImg.src = './img/ligada.jpg';
			buttonOnOff.textContent = 'Desligar';
			isLampOn = true;

		// Desligando a lampada
		} else {

			lampadaImg.src = './img/desligada.jpg';
			buttonOnOff.textContent = 'Ligar';
			isLampOn = false;

		}			
  }

}

function brokenLamp () {

	isLampBroken = true;
	lampadaImg.src = './img/quebrada.jpg'; 

}

buttonOnOff.addEventListener('click', turnOnOffLamp);

// Quando o ponteiro do mouse estiver sobre a lampada
lampadaImg.addEventListener('mouseover', turnOnOffLamp);

// Quando o ponteiro do mouse sair de sobre a lampada
lampadaImg.addEventListener('mouseleave', turnOnOffLamp);

// Evento para duplo click com botao esquerdo
lampadaImg.addEventListener('dblclick', brokenLamp);

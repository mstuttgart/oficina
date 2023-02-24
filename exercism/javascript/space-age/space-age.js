//
// This is only a SKELETON file for the 'Space Age' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const age = (planet, ageSeconds) => {
  
  // Ano terreste: 365 dias, 5 horas, 48 minutos e 46 segundos
  const earthYear = 31557600;

  function getPlanetYear(ratio=1) {
    let totalAge = (ageSeconds / (ratio * earthYear)).toFixed(2)
    return Number.parseFloat(totalAge);
  }

  let ratio = null;

  switch (planet) {

    case 'earth':
      ratio = 1;
      break;
    
    case 'mercury':
      ratio = 0.2408467;
      break;

    case 'venus':
      ratio = 0.61519726;
      break;
    
    case 'mars':
      ratio = 1.8808158;
      break;
    
    case 'jupiter':
      ratio = 11.862615;
      break;
    
    case 'saturn':
      ratio = 29.447498;
      break;
    
    case 'uranus':
      ratio = 84.016846;
      break;
    
    case 'neptune':
      ratio = 164.79132;
      break;
    
    default:
      break;

  }

  return getPlanetYear(ratio);

};

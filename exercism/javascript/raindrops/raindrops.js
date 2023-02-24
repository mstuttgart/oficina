//
// This is only a SKELETON file for the 'Raindrops' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const convert = (n) => {

  let response = '';

  if (n % 3 === 0)
    response += 'Pling';

  if (n % 5 == 0)
    response += 'Plang';

  if (n % 7 == 0)
    response += 'Plong';

  if (!response)
    response = n.toString();

  return response;
};

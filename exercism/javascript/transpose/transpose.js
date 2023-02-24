//
// This is only a SKELETON file for the 'Transpose' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const transpose = (input) => {

  if (!input.length)
    return [];

  const arrayLength = input.map((item) => {
    return item.length;
  })

  // COnseguimos o maior comprimento da linha
  const maxLength = Math.max(...arrayLength);

  // Separamos a string das colunas
  const newArray = input.map((item) => {
    item = item.padEnd(maxLength, '@');
    return item.split('');
  })


  let finalArray = [];

  for (let item of newArray) { // item == Array

    for (let i in item) {

      if (finalArray[i] === undefined)
        finalArray[i] = '';

      finalArray[i] += item[i];

    }

  }

  // Ajustamos os espaçamentos antes e depois do valores
  finalArray.forEach((item, index, arr) => {
    let a = null;

    // Substitui @ no fim da string por ''
    a = item.replace(/@+$/, '');

    // Substitui @ no comeco da string por ' '
    a = a.replaceAll('@', ' ');

    arr[index] = a;

  });

  return finalArray;

};

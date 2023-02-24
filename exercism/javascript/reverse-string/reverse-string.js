//
// This is only a SKELETON file for the 'Reverse String' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const reverseString = (str) => {
  let arrayWord = str.split('');
  arrayWord.reverse();
  return arrayWord.join('');
};

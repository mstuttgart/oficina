//
// This is only a SKELETON file for the 'Prime Factors' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const primeFactors = (n) => {

  const factors = [];

  if (n === 1)
    return factors;

  let remainder = 0;
  let divisor = 2;

  do {

    remainder = n % divisor;

    if (remainder === 0) {
      factors.push(divisor);
      n /= divisor;
    } else {
      divisor++;
    }

  } while (n !== 1);


  return factors;

};

//
// This is only a SKELETON file for the 'Gigasecond' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const gigasecond = (initialDate) => {
  
  const finalDate = new Date();
  const gigasecondms = 1000000000 * 1000; // em milisegundos

  finalDate.setTime(initialDate.getTime() + gigasecondms);
  return finalDate;
};

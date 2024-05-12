//
// This is only a SKELETON file for the 'Resistor Color Duo' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

import { NOMEM } from "dns";

export const decodedValue = (colors) => {
  let color1 = COLORS.indexOf(colors[0]);
  let color2 = COLORS.indexOf(colors[1]);

  console.log(color1)
  console.log(color2)

  return color1 * 10 + color2;
};

const COLORS = ['black', 'brown', 'red', 'orange', 'yellow', 'green', 'blue', 'violet', 'grey', 'white'];

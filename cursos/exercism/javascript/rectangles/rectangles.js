//
// This is only a SKELETON file for the 'Rectangles' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export function count(rect) {
  if (rect.length === 0 || (rect.length === 1 && rect[0].trim() === "")) {
    return 0;
  }

  const firstPos = rect[0].indexOf('+');

  for (let i = firstPos + 1; i < rect[0].length; i++) {

    
    if (rect[0][i] == '-') {

    }
  }
}

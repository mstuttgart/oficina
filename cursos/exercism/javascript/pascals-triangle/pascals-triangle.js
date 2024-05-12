//
// This is only a SKELETON file for the 'Pascals Triangle' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const rows = (n) => {

  const row = [];

  if (n === 0)
    return row;

  // row.push([1]);

  // if (n === 1)
  //   return row;

  for (let i = 0; i < n; i++) {

    row[i] = []
  
    for (let j = 0; j < i + 1; j++) {

      if (j === 0 || j === i) {
        row[i].push(1);
      } else {
        row[i].push(row[i-1][j] + row[i-1][j-1]);
      }

    }

  }
  
  return row;

};

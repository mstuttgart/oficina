//
// This is only a SKELETON file for the 'Anagram' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const findAnagrams = (target, candidates) => {

  // Contabiliza a ocorrencia de cada caracter de 'text'
  function counterChars(text) {

    const obj = {};

    for (let c of text) {

      const cLower = c.toLowerCase();

      if (!obj[cLower]) {
        obj[cLower] = 0;
      }

      // Contabiliza ocorrencia do valor de c na string text
      obj[cLower]++;

    }

    return obj;

  };

  // Verifica se o numero de ocorrencias do caracter
  // de cada string coincidem. Se sim, é porque podem
  // ser anagramas
  function checkCandidate(targetObj, candidateObj) {

    for (let c in targetObj) {

      if (targetObj[c] !== candidateObj[c]) {
        return false;
      }

    }

    return true;

  };

  const anagrams = [];

  const targetObj = counterChars(target);

  for (let cand of candidates) {

    if (target.length !== cand.length || target.toLowerCase() === cand.toLowerCase()) {
      continue
    }
      
    const candObj = counterChars(cand);

    if (checkCandidate(targetObj, candObj)) {
      anagrams.push(cand);
    }

  }

  return anagrams;

};

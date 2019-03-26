function calcular() {
  // Capturamos os valores a serem calculados
  var valor_a = document.getElementById("valor_a").value;
  var valor_b = document.getElementById("valor_b").value;

  // Caprtuamos qual o operador selecionado
  var operador = document.getElementById("operador").value;

  var res = 0;

  switch (operador) {
    case "somar":
      // Todos os valores sao enviados como string, logo
      // precisamos converte-los
      res = parseFloat(valor_a) + parseFloat(valor_b);
      break;

    case "subtracao":
      res = parseFloat(valor_a) - parseFloat(valor_b);
      break;

    case "multiplicacao":
      res = parseFloat(valor_a) * parseFloat(valor_b);
      break;

    case "divisao":
      res = parseFloat(valor_a) / parseFloat(valor_b);
      break;

    default:
      console.log("Operação invalida");
  }

  // Atribuimos o resultado da operacao no campo
  // de resultado
  document.getElementById("resultado").value = res;
}

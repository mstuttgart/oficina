const gameLogic = {
  rock: {
    scissor: "You Win! Rock beats Scissor",
    paper: "You Lose! Paper beats Rock",
    rock: "Ties",
  },
  scissor: {
    rock: "You Lose! Rock beats Scissor",
    paper: "You Win! Scissor beats Paper",
    scissor: "Ties",
  },
  paper: {
    rock: "You Win! Paper beats Rock",
    scissor: "You Lose! Scissor beats Paper",
    paper: "Ties",
  },
};

function getComputeChoice() {
  // gerar valor entre 1 e 3 (inclusive)
  min = 1;
  max = 4;

  const values = {
    1: "rock",
    2: "paper",
    3: "scissor",
  };

  let idx = Math.floor(Math.random() * (max - min) + min);
  return values[idx];
}

function playRound(playerSelection, computeSelection) {
  // fix case o playerSelection
  playerSelection = playerSelection.toLowerCase();
  return gameLogic[playerSelection][computeSelection];
}

function game() {
  let playerLoop = 5;

  while (playerLoop > 0) {
    let playerSelection = prompt("What you choice");
    let computeSelection = getComputeChoice();

    console.log(`Player choice:${playerSelection}`);
    console.log(`Computer choice:${computeSelection}`);

    playerLoop--;

    result = playRound(playerSelection, computeSelection);

    if (result == "Ties") {
      playerLoop++;
    }

    console.log(result);
  }
}

game();

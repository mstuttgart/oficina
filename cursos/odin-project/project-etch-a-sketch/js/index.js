const container = document.getElementById("container");

const containerWidth = 320;
const containerHeight = 320;

const gridSize = 16;

const totalWidth = containerWidth / gridSize;
const totalHeight = containerHeight / gridSize;

// for (let i = 0; i < totalHeight; i++) {
  for (let j = 0; j < totalWidth * totalHeight; j++) {
    let divGrid = document.createElement("div");
    divGrid.className = "grid";
    container.appendChild(divGrid);
  }
 // let divBreak = document.createElement("div");
  // divBreak.className = "line-break";
  // container.appendChild(divBreak);
// }

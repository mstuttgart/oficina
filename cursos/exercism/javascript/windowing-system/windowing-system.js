// @ts-check

/**
 * Implement the classes etc. that are needed to solve the
 * exercise in this file. Do not forget to export the entities
 * you defined so they are available for the tests.
 */
export function Size(width = 80, height = 60) {
  this.width = width;
  this.height = height;
}

Size.prototype.resize = function (newWidth, newHeight) {
  this.width = newWidth;
  this.height = newHeight;
};

export function Position(x = 0, y = 0) {
  this.x = x;
  this.y = y;
}

Position.prototype.move = function (newX, newY) {
  this.x = newX;
  this.y = newY;
};

export class ProgramWindow {

  constructor() {
    this.screenSize = new Size(800, 600);
    this.size = new Size();
    this.position = new Position();
  }

  resize(newSize) {

    let newWidth = newSize.width > 1 ? newSize.width : 1;
    let newHeight = newSize.height > 1 ? newSize.height : 1;

    let w = this.screenSize.width - (this.position.x + newWidth);
    let h = this.screenSize.height - (this.position.y + newHeight);

    this.size.width = w < 0 ? newWidth - Math.abs(w) : newWidth;
    this.size.height = h < 0 ? newHeight - Math.abs(h) : newHeight;

  }

  move(newPosition) {

    let newX = newPosition.x < 0 ? 0 : newPosition.x;
    let newY = newPosition.y < 0 ? 0 : newPosition.y;

    let x = this.screenSize.width - (this.size.width + newX);
    let y = this.screenSize.height - (this.size.height + newY);

    this.position.x = x < 0 ? newX - Math.abs(x) : newX;
    this.position.y = y < 0 ? newY - Math.abs(y) : newY;

  }

}

export function changeWindow(programWindow) {

  programWindow.resize(new Size(400, 300));
  programWindow.move(new Position(100, 150));

  return programWindow;

}


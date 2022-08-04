const $ = (selector) => document.querySelector(selector);
const $$ = (selector) => document.querySelectorAll(selector);

const addMoveEvent = () => {
  [...$$('.block')].forEach((element) => {
    element.addEventListener('click', moveElement);
  });
};

const items = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 0],
];

const dx = [-1, 1, 0, 0];
const dy = [0, 0, -1, 1];
const rerender = () => {
  const parent = $('.box');
  parent.innerHTML = '';
  items.forEach((row) => {
    row.forEach((number) => {
      if (number == 0) {
        parent.innerHTML += '<div class="puzzle blank"></div>\n';
      } else {
        parent.innerHTML += `<div class="puzzle block"><p>${number}</p></div>`;
      }
    });
  });
  addMoveEvent();
};

const moveElement = (event) => {
  const number = event.currentTarget.firstChild.innerHTML;
  const cols = items[0].length;
  const rows = items.length;
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (items[i][j] == parseInt(number)) {
        for (let dir = 0; dir < 4; dir++) {
          const x = i + dx[dir];
          const y = j + dy[dir];
          if (x < 0 || y < 0 || x >= rows || y >= cols) continue;
          if (items[x][y] == 0) {
            items[i][j] = 0;
            items[x][y] = parseInt(number);
            rerender();
            return;
          }
        }
      }
    }
  }
};

document.addEventListener('DOMContentLoaded', function () {
  addMoveEvent();
  $('#create-puzzle').addEventListener('click', () => {
    const str = $('textarea').value;
    for (let i = 0; i < 9; i++) {
      const row = parseInt(i / 3);
      const col = parseInt(i % 3);
      items[row][col] = parseInt(str[i]);
    }
    rerender();
  });
});

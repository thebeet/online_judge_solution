class Link4DirectionNode {
    constructor(data) {
        this.data = data;
        this.left = this;
        this.right = this;
        this.up = this;
        this.down = this;
    }
}

class DancingLinkAlgorithm {
    constructor(rowSize, columnSize) {
        this.root = new Link4DirectionNode({type: 'Root'});
        this.rowSize = rowSize;
        this.columnSize = columnSize;
        this.rowHead = [];
        this.columnHead = [];
        for (let i = 0; i < this.columnSize; i++) {
            let columnHead = new Link4DirectionNode({type: 'ColumnHead', column: i, count: 0});
            columnHead.left = this.root.left;
            columnHead.right = this.root;
            this.root.left.right = columnHead;
            this.root.left = columnHead;
            this.columnHead.push(columnHead);
        }
        for (let i = 0; i < this.rowSize; i++) {
            let rowHead = new Link4DirectionNode({type: 'rowHead', row: i, count: 0});
            rowHead.up = this.root.up;
            rowHead.down = this.root;
            this.root.up.down = rowHead;
            this.root.up = rowHead;
            this.rowHead.push(rowHead);
        }
    }

    addCell(x, y) {
        let cell = new Link4DirectionNode({type: 'cell', row: x, column: y});
        let row = this.rowHead[x];
        let column = this.columnHead[y];
        row.data.count += 1;
        column.data.count += 1;
        cell.left = row.left;
        cell.right = row;
        row.left.right = cell;
        row.left = cell;
        cell.up = column.up;
        cell.down = column;
        column.up.down = cell;
        column.up = cell;
    }

    hideRow(row) {
        for (let pointer = row.right; pointer !== row ; pointer = pointer.right) {
            pointer.up.down = pointer.down;
            pointer.down.up = pointer.up;
        }
    }

    showRow(row) {
        for (let pointer = row.right; pointer !== row ; pointer = pointer.right) {
            pointer.up.down = pointer;
            pointer.down.up = pointer;
        }
    }

    hideColumn(column) {
        column.left.right = column.right;
        column.right.left = column.left;
    }

    showColumn(column) {
        column.left.right = column;
        column.right.left = column;
    }

    pickRow(row) {
        let rowHide = [];
        for (let pointer = row.right; pointer.data.type === 'cell'; pointer = pointer.right) {
            let column = this.columnHead[pointer.data.column];
            for (let pointerC = column.down; pointerC.data.type === 'cell'; pointerC = pointerC.down) {
                this.hideRow(this.rowHead[pointerC.data.row]);
                rowHide.push(this.rowHead[pointerC.data.row]);
            }
            this.hideColumn(column);
        }
        return rowHide;
    }

    solve(rowChange, callback) {
        if (this.root.right !== this.root) {
            let currentColumn = this.root.right;
            for (let pointer = currentColumn.down; pointer !== currentColumn; pointer = pointer.down) {
                if (rowChange(pointer.data.row, true)) {
                    let row = this.rowHead[pointer.data.row];
                    let rowHide = this.pickRow(row);
                    if (this.solve(rowChange, callback)) {
                        return true;
                    }
                    rowChange(pointer.data.row, false);
                    for (let pointer = row.left; pointer.data.type === 'cell'; pointer = pointer.left) {
                        let column = this.columnHead[pointer.data.column];
                        this.showColumn(column);
                    }
                    for (let i = rowHide.length - 1; i >= 0; i--) {
                        this.showRow(rowHide[i]);
                    }
                }
            }
        } else {
            return callback(this);
        }
    }
}

class Soduku {
    constructor(N, border) {
        this.N = N;
        this.n = N * N;
        this.border = border;
        // this.dlx = new DancingLinkAlgorithm(this.n * this.n * this.n, this.n * this.n * 4);
        this.dlx = new DancingLinkAlgorithm(this.n * this.n * this.n, this.n * this.n * 3);
        for (let x = 0; x < this.n; ++x) {
            for (let y = 0; y < this.n; ++y) {
                let rowCount = x * this.n * this.n + y * this.n;
                // let cell = Math.floor(x / this.N) * this.N + Math.floor(y / this.N);
                for (let num = 0; num < this.n; ++num) {
                    this.dlx.addCell(rowCount + num, this.n * x + y);
                    this.dlx.addCell(rowCount + num, this.n * this.n + x * this.n + num);
                    this.dlx.addCell(rowCount + num, this.n * this.n * 2 + y * this.n + num);
                    //this.dlx.addCell(rowCount + num, this.n * this.n * 3 + cell * this.n + num);
                }
            }
        }
        this.table = [];
        for (let i = 0; i < this.n; ++i) {
            let row = [];
            for (let j = 0; j < this.n; ++j) {
                row.push(0);
            }
            this.table.push(row);
        }
    }

    solve() {
        this.dlx.solve((row, push) => {
            let x = Math.floor(row / (this.n * this.n));
            let y = Math.floor(row / this.n) % this.n;
            if (push) {
                let num = row % this.n + 1;
                this.table[x][y] = num;
                if (this.checkBorder(x, y)) {
                    return true;
                } else {
                    this.table[x][y] = 0;
                }
            } else {
                this.table[x][y] = 0;
            }
            return false;
        }, () => {
            this.printSolution();
            return true;
        });
    }

    _checkBorder(x, y, dx, dy, r) {
        if (r > 0) {
            let d = 0;
            let p = 0;
            let smallItemLeft = 0;
            for (let i = 0; i < 9; ++i) {
                if (this.table[x][y] === 0) {
                    return true;
                }
                if (p < this.table[x][y]) {
                    smallItemLeft += this.table[x][y] - p - 1;
                    p = this.table[x][y];
                    d++;
                    if (p >= 8) {
                        return d + (9 - p) === r;
                    }
                    if (9 - p + d < r) {
                        return false;
                    }
                    if (8 - i - smallItemLeft + d < r) {
                        return false;
                    }
                    if (d >= r) {
                        return false;
                    }
                } else {
                    smallItemLeft -= 1;
                }
                x += dx;
                y += dy;
            }
        }
        return true;
    }

    checkBorder(x, y) {
        return (this._checkBorder(0, y, 1, 0, this.border[0][y]) &&
                this._checkBorder(x, 0, 0, 1, this.border[1][x]) &&
                this._checkBorder(8, y, -1, 0, this.border[2][y]) &&
                this._checkBorder(x, 8, 0, -1, this.border[3][x]));
    }

    addNotConstants(x, y, num) {
        let rowIndex = x * this.n * this.n + y * this.n + num;
        let row = this.dlx.rowHead[rowIndex];
        this.dlx.hideRow(row);
    }

    addConstants(x, y, num) {
        let rowIndex = x * this.n * this.n + y * this.n + num;
        let row = this.dlx.rowHead[rowIndex];
        this.dlx.pickRow(row);
        this.table[x][y] = num + 1;
    }

    printSolution() {
        console.log(' = = = = = = = = =');
        for (let i = 0; i < this.n; ++i) {
            let output = '';
            for (let j = 0; j < this.n; ++j) {
                output += ' ' + this.table[i][j];
            }
            console.log(output);
        }
    }
}

var solveSudoku = function(board, border) {
    let t = new Soduku(3, border);
    for (let x = 0; x < 9; x++) {
        for (let y = 0; y < 9; y++) {
            if (board[x][y] !== '.') {
                t.addConstants(x, y, parseInt(board[x][y], 10) - 1);
            }
        }
    }
    for (let i = 0; i < 9; ++i) {
        for (let j = 1; j < border[0][i]; ++j) {
            for (let k = 1; k <= j; k++) {
                t.addNotConstants(j - k, i, 9 - k);
            }
        }
        for (let j = 1; j < border[1][i]; ++j) {
            for (let k = 1; k <= j; k++) {
                t.addNotConstants(i, j - k, 9 - k);
            }
        }

        for (let j = 1; j < border[2][i]; ++j) {
            for (let k = 1; k <= j; k++) {
                t.addNotConstants(8 - j + k, i, 9 - k);
            }
        }
        for (let j = 1; j < border[3][i]; ++j) {
            for (let k = 1; k <= j; k++) {
                t.addNotConstants(i, 8 - j + k, 9 - k);
            }
        }
    }
    t.solve();
};

solveSudoku([
    '....3....',
    '.4.9.....',
    '.......6.',
    '........8',
    '..3.....6',
    '...847...',
    '......4.9',
    '4.9.....3',
    '..6...987',
], [
    [0, 3, 0, 0, 3, 0, 0, 0, 4],
    [5, 2, 0, 3, 0, 0, 0, 3, 3],
    [3, 0, 0, 3, 3, 4, 0, 0, 0],
    [0, 5, 4, 2, 2, 4, 0, 4, 3],
]);

/**
    '....3....',
    '.4.......',
    '.......6.',
    '.........',
    '..3.....6',
    '...847...',
    '......4..',
    '4.......3',
    '..6......',
 */
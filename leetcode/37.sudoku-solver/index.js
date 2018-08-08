
class LinkedSparseMatrixCell {
    constructor(data) {
        this.data = data;
        this.left = this;
        this.right = this;
        this.up = this;
        this.down = this;
    }
}

class LinkedSparseMatrix {
    constructor(rowSize, columnSize) {
        this.root = new LinkedSparseMatrixCell({type: 'Root'});
        this.rowSize = rowSize;
        this.columnSize = columnSize;
        this.rowHead = [];
        this.columnHead = [];
        for (let i = 0; i < this.columnSize; i++) {
            let columnHead = new LinkedSparseMatrixCell({type: 'ColumnHead', column: i, count: 0});
            columnHead.left = this.root.left;
            columnHead.right = this.root;
            this.root.left.right = columnHead;
            this.root.left = columnHead;
            this.columnHead.push(columnHead);
        }
        for (let i = 0; i < this.rowSize; i++) {
            let rowHead = new LinkedSparseMatrixCell({type: 'rowHead', row: i, count: 0});
            rowHead.up = this.root.up;
            rowHead.down = this.root;
            this.root.up.down = rowHead;
            this.root.up = rowHead;
            this.rowHead.push(rowHead);
        }
    }

    addCell(x, y) {
        let cell = new LinkedSparseMatrixCell({type: 'cell', row: x, column: y});
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
}

class DancingLinkAlgorithm {
    constructor(rowSize, columnSize) {
        this.martix = new LinkedSparseMatrix(rowSize, columnSize);
    }

    addCell(x, y) {
        let cell = new LinkedSparseMatrixCell({type: 'cell', row: x, column: y});
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

    solve(solution) {
        let flag = false;
        if (this.root.right !== this.root) {
            let currentColumn = this.root.right;
            for (let pointer = currentColumn.down; pointer !== currentColumn; pointer = pointer.down) {
                solution.push(pointer.data.row);
                let row = this.rowHead[pointer.data.row];
                let rowHide = [];
                for (let pointer = row.right; pointer.data.type === 'cell'; pointer = pointer.right) {
                    let column = this.columnHead[pointer.data.column];
                    for (let pointerC = column.down; pointerC.data.type === 'cell'; pointerC = pointerC.down) {
                        this.hideRow(this.rowHead[pointerC.data.row]);
                        rowHide.push(this.rowHead[pointerC.data.row]);
                    }
                    this.hideColumn(column);
                }
                if (this.solve(solution)) {
                    return true;
                }
                solution.pop();
                for (let pointer = row.left; pointer.data.type === 'cell'; pointer = pointer.left) {
                    let column = this.columnHead[pointer.data.column];
                    this.showColumn(column);
                }
                for (let i = rowHide.length - 1; i >= 0; i--) {
                    this.showRow(rowHide[i]);
                }
            }
            return false;
        } else {
            return true;
        }
    }

    _debug() {
        for (let row of this.rowHead) {
            let output = '';
            let p = 0;
            for (let pointer = row.right; pointer !== row; pointer = pointer.right) {
                for ( ; p < pointer.data.column; p++) {
                    output = output + ' 0';
                }
                output += ' 1';
                p = pointer.data.column + 1;
            }
            for ( ; p < this.columnSize; p++) {
                output += ' 0';
            }
            console.log(output);
        }
    }
}

class Soduku {
    constructor(N) {
        this.N = N;
        this.n = N * N;
        this.dlx = new DancingLinkAlgorithm(this.n * this.n * this.n, this.n * this.n * 4);
        for (let x = 0; x < this.n; ++x) {
            for (let y = 0; y < this.n; ++y) {
                let rowCount = x * this.n * this.n + y * this.n;
                let cell = Math.floor(x / this.N) * this.N + Math.floor(y / this.N);
                for (let num = 0; num < this.n; ++num) {
                    this.dlx.addCell(rowCount + num, this.n * x + y);
                    this.dlx.addCell(rowCount + num, this.n * this.n + x * this.n + num);
                    this.dlx.addCell(rowCount + num, this.n * this.n * 2 + y * this.n + num);
                    this.dlx.addCell(rowCount + num, this.n * this.n * 3 + cell * this.n + num);
                }
            }
        }
        this.solution = [];
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
        let result = this.dlx.solve(this.solution);
        if (result) {
            for (let item of this.solution) {
                let x = Math.floor(item / (this.n * this.n));
                let y = Math.floor(item / this.n) % this.n;
                let num = item % this.n;
                this.table[x][y] = num + 1;
            }
        }
        return result;
    }

    addConstants(x, y, num) {
        let rowIndex = x * this.n * this.n + y * this.n + num;
        let row = this.dlx.rowHead[rowIndex];
        for (let pointer = row.right; pointer.data.type === 'cell'; pointer = pointer.right) {
            let column = this.dlx.columnHead[pointer.data.column];
            for (let pointerC = column.down; pointerC.data.type === 'cell'; pointerC = pointerC.down) {
                this.dlx.hideRow(this.dlx.rowHead[pointerC.data.row]);
            }
            this.dlx.hideColumn(column);
        }
        this.solution.push(x * this.n * this.n + y * this.n + num);
    }

    printSolution() {
        for (let i = 0; i < this.n; ++i) {
            let output = '';
            for (let j = 0; j < this.n; ++j) {
                output += ' ' + this.table[i][j];
            }
            console.log(output);
        }
    }

}


/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
    let t = new Soduku(3);
    for (let x = 0; x < 9; x++) {
        for (let y = 0; y < 9; y++) {
            if (board[x][y] !== '.') {
                t.addConstants(x, y, parseInt(board[x][y], 10) - 1);
            }
        }
    }
    t.solve();
    for (let item of t.solution) {
        let x = Math.floor(item / (9 * 9));
        let y = Math.floor(item / 9) % 9;
        let num = item % 9;
        board[x][y] = '' + (num + 1);
    }
    t.printSolution();
};


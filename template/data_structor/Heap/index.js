class Heap {
    constructor(cmp) {
        this.size = 0;
        this.data = [];
        if (cmp) {
            this._cmp = cmp;
        } else {
            this._cmp = (a, b) => {
                if (a < b) return -1;
                if (a > b) return 1;
                return 0;
            };
        }
    }

    top() {
        return this.size > 0 ? this.data[0] : null;
    }

    pop() {
        if (this.size > 0) {
            let top = this.top();
            if (this.size > 1) {
                this._swap(0, this.size - 1);
            }
            this.size -= 1;
            this.data.splice(this.size);
            if (this.size > 0) {
                this._turndown(0);
            }
            return top;
        }
        return null;
    }

    push(value) {
        this.size += 1;
        this.data.push(value);
        this._turnup(this.size - 1);
    }

    _swap(index1, index2) {
        let tmp = this.data[index1];
        this.data[index1] = this.data[index2];
        this.data[index2] = tmp;
    }

    _turnup(index) {
        if (index > 0) {
            let parentIndex = index >> 1;
            if (this._cmp(this.data[index], this.data[parentIndex]) === -1) {
                this._swap(index, parentIndex);
                this._turnup(parentIndex);
            }
        }
    }

    _turndown(index) {
        let child1 = index * 2;
        let child2 = child1 + 1;
        let child = index;
        if ((child1 < this.size) && (this._cmp(this.data[child1], this.data[child]) === -1)) {
            child = child1;
        }
        if ((child2 < this.size) && (this._cmp(this.data[child2], this.data[child]) === -1)) {
            child = child2;
        }
        if (child !== index) {
            this._swap(index, child);
            this._turndown(child);
        }
    }
}


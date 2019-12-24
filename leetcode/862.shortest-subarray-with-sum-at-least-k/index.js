
class RMQ {
    constructor(arr) {
        this.arr = arr;
        this._extSize = 1;
        while (this._extSize < this.arr.length) {
            this._extSize *= 2;
        }
        this._extendArr = new Array(this._extSize * 2).fill(-1);
        for (let i = 0; i < this.arr.length; i++) {
            this._extendArr[i + this._extSize] = i;
        }
        for (let i = this._extSize - 1; i > 0; --i) {
            this._extendArr[i] = this._selectMinPos(i * 2, i * 2 + 1);
        }
    }

    queryMinPos(from, to) {
        let start = from + this._extSize;
        let end = to + this._extSize;
        let ans = start;
        while (start <= end) {
            ans = this._selectMinPos(ans + this._extSize, this._selectMinPos(start, end) + this._extSize);
            if (start === end) {
                break;
            }
            start = (start + 1) >> 1;
            end = (end - 1) >> 1;
        }
        return ans;
    }

    queryMin(from, to) {
        return this.arr[this.queryMinPos(from, to)];
    }

    _selectMinPos(p1, p2) {
		if (this._extendArr[p1] === -1) {
            return this._extendArr[p2];
        }
		if (this._extendArr[p2] === -1) {
            return this._extendArr[p1];
        }
		return this.arr[this._extendArr[p1]] < this.arr[this._extendArr[p2]] ? this._extendArr[p1] : this._extendArr[p2];
	}
}

/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var shortestSubarray = function(A, K) {
    let sums = [];
    let sum = 0;
    sums.push(sum);
    for (let item of A) {
        sum += item;
        sums.push(sum);
    }
    let rmq = new RMQ(sums);

    let test = (wide, K) => {
        for (let i = 1; i <= A.length; ++i) {
            if (sums[i] - rmq.queryMin(Math.max(i - wide, 0), i - 1) >= K) {
                return true;
            }
        }
        return false;
    };

    let lo = 0;
    let hi = A.length + 1;
    while (lo + 1 < hi) {
        let mid = (lo + hi) >> 1;
        if (test(mid, K)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi > A.length ? -1 : hi;
};

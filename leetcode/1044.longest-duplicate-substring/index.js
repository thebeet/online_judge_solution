/**
 * @param {string} s
 * @return {string}
 */

 class RMQ {
    constructor(n, cmp) {
        this.N = n;
        this.cmp = cmp;
        this.M = 1 << Math.ceil(Math.log2(this.N));
        this.rmq = new Array(this.M << 1);
        this.init();
    }

    init() {
        for (let i = this.M; i < this.M + this.N; ++i) {
            this.rmq[i] = i - this.M;
        }
        for (let i = this.M + this.N; i < this.M * 2; ++i) {
            this.rmq[i] = Infinity;
        }
        for (let i = this.M - 1; i > 0; --i) {
            this.rmq[i] = this.min(i << 1, (i << 1) + 1);
        }
    }

    findMinPos(start, end) {
        let pstart = start + this.M, pend = end + this.M;
        let ans = start;
        while (pstart <= pend) {
            ans = this.min(ans + this.M, this.min(pstart, pend) + this.M);
            pstart = (pstart + 1) >> 1;
            pend = (pend - 1) >> 1;
        }
        return ans;
    }

    min(p1, p2) {
        if (this.rmq[p1] === Infinity) {
            return this.rmq[p2];
        }
        if (this.rmq[p2] === Infinity) {
            return this.rmq[p1];
        }
        return (this.cmp(this.rmq[p1], this.rmq[p2]) < 0) ? this.rmq[p1] : this.rmq[p2];
    }
}

class SuffixArray {
    constructor(str) {
        this.str = str;
        this.N = str.length;
        this.sa = new Array(this.N);
        this.rank = new Array(this.N);
        this.height = new Array(this.N);
        this.doubling();
    }

    doubling() {
        const MaxCharCode = 256;
        let sum = new Array(MaxCharCode).fill(0);
        let use = new Array(MaxCharCode).fill(0);
        for (let i = 0; i < this.N; ++i) {
            ++sum[this.str[i].charCodeAt()];
        }
        for (let i = 1; i < MaxCharCode; ++i) {
            sum[i] += sum[i - 1];
        }
        for (let i = 0; i < this.N; ++i) {
            this.sa[i] = sum[this.str[i].charCodeAt() - 1] + use[this.str[i].charCodeAt() - 1];
            this.rank[i] = sum[this.str[i].charCodeAt() - 1];
            ++use[this.str[i].charCodeAt() - 1];
        }
        let k = 1;
        let cmp = (a, b) => {
            if (this.rank[a] === this.rank[b]) {
                if (a + k >= this.N) return -1;
                if (b + k >= this.N) return 1;
                return this.rank[a + k] - this.rank[b + k];
            }
            return this.rank[a] - this.rank[b];
        };
        while (k < this.N) {
            this.sa.sort(cmp);
            let newRank = new Array(this.N);
            newRank[this.sa[0]] = 0;
            for (let i = 1; i < this.N; ++i) {
                newRank[this.sa[i]] = (cmp(this.sa[i - 1], this.sa[i]) < 0) ? i : newRank[this.sa[i - 1]];
            }
            this.rank = newRank;
            k <<= 1;
        }
    }

    initLCP() {
        let h = new Array(this.N);
        for (let i = 0; i < this.N; ++i) {
            if (this.rank[i] === 0) {
                h[i] = 0;
                this.height[this.rank[i]] = 0;
                continue;
            }
            let j = 0;
            if ((i !== 0) && (h[i - 1] > 1)) {
                j = h[i - 1] - 1;
            }
            while ((this.sa[this.rank[i] - 1] + j < this.N) && (this.str[this.sa[this.rank[i] - 1] + j] === this.str[this.sa[this.rank[i]] + j])) {
                j++;
            }
            h[i] = j;
            this.height[this.rank[i]] = j;
        }
        this.rmq = new RMQ(this.n, (a, b) => {
            return this.height[a] - this.height[b];
        });
    }

    LCP(i, j) {
        if (i > j) return this.LCP(j, i);
        if (i === j) return this.N - this.sa[i] + 1;
        return this.rmq.findMinPos(i, j);
    }
}

var longestDupSubstring = function(s) {
    let n = s.length;
let a = new SuffixArray(s);
a.initLCP();
ans = 0;
ansp = -1;
for (let i = 0; i < n; ++i) {
    if (ans < a.height[i]) {
        ans = a.height[i];
        ansp = i;
    }
}
if (ans > 0) {
    return s.substring(a.sa[ansp], a.sa[ansp] + ans);
} else {
    return '';
}
};
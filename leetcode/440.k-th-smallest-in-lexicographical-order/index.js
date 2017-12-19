/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */


var findKthNumber = function(n, k) {
    var p10 = [1,
               10,
               100,
               1000,
               10000,
               100000,
               1000000,
               10000000,
               100000000,
               1000000000,
               10000000000,
               100000000000];

    var countPre = function (pre, n) {
      var count = 0;
        for (var i = 0; pre * p10[i] <= n; i++) {
            count += Math.min(n - pre * p10[i] + 1, p10[i]);
        }
        return count;
    };

    var findKthNumberWithPre = function(pre, n, k) {
        if (pre > 0) {
            if (k === 1) {
                return pre;
            }
            k -= 1;
        }
        for (var next = ((pre === 0) ? 1 : 0); next <= 9; next++) {
            var newPre = pre * 10 + next;
            var newPreCount = countPre(newPre, n);
            if (newPreCount >= k) {
                return findKthNumberWithPre(newPre, n, k);
            } else {
                k -= newPreCount;
            }
        }
        return -1;
    };

    return findKthNumberWithPre(0, n, k);
};

console.log(findKthNumber(1, 1));

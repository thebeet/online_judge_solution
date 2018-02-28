/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
        let result = 0;
    let current = 0;
    let N = nums.length;
    let lo = 0, hi = nums[0];
    for ( ; lo < N - 1; ) {
        if (lo >= hi) {
            return false;
        }
        let next = hi;
        for (let i = lo + 1; i <= hi; i++) {
            next = Math.max(next, i + nums[i]);
        }
        lo = hi;
        hi = next;

    }
    return true;
};



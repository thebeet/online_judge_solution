/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    let result = 0;
    let current = 0;
    let N = nums.length;
    let lo = 0, hi = nums[0];
    for ( ; lo < N - 1; ) {
        let next = hi;
        for (let i = lo + 1; i <= hi; i++) {
            next = Math.max(next, i + nums[i]);
        }
        lo = hi;
        hi = next;
        result += 1;
    }
    return result;
};

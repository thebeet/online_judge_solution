/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumGap = function(nums) {
    let mi = nums[0];
    let mx = nums[0];
    let n = nums.length;
    if (n <= 1) return 0; 
    for (let num of nums) {
        mi = Math.min(num, mi);
        mx = Math.max(num, mx);
    }
    let div = Math.ceil((mx - mi) / (n - 1));
    let result = div;
    let gap = {};
    for (let num of nums) {
        let d = Math.floor(num / div);
        let m = num % result;
        if (d in gap) {
            gap[d].mx = Math.max(gap[d].mx, m);
            gap[d].mi = Math.min(gap[d].mi, m);
        } else {
            gap[d] = {
                mx: m,
                mi: m
            };
        }
    }
    let pre = null;
    for (let d in gap) {
        if (pre !== null) {
            result = Math.max(result, gap[d].mi - gap[pre].mx + (d - pre) * div);
        } 
        pre = d;
    }
    return result;
};


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var checkSubarraySum = function(nums, k) {
    if (k === 0) {
        let pre = -1;
        for (let num of nums) {
            if ((pre === 0) && (num === 0)) {
                return true;
            }
            pre = num;
        }
        return false;
    }
    let hash = {0: true};
    let current = k;
    let pre = -1;
    for (let num of nums) {
        num %= k;
        if ((pre === 0) && (num === 0)) {
            return true;
        }
        pre = num;
        if ((current === 0) && (num === 0)) {
            return true;
        }
        current = (current + num) % k;
        if (num > 0) {
            if (current in hash) {
                return true;
            } else {
                hash[current] = true;
            }
        
        }
    }
    return false;
};

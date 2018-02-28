/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let N = nums.length;
    let lo = 0;
    let hi = N - 1;
    while (nums[lo] > nums[hi]) {
        if (lo + 1 === hi) {
            return nums[hi];
        }
        let mid = (lo + hi) >> 1;
        let flag = false;
        if (nums[mid] < nums[lo]) {
            flag = true;
        }
        if (nums[mid] > nums[hi]) {
            flag = false;
        }
        if (flag) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return nums[lo];
};

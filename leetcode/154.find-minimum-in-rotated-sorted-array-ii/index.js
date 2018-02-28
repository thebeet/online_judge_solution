/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let firstNum = nums[0];
    let preNum = nums[0];
    let newNums = [];
    newNums.push(firstNum);
    for (let num of nums) {
        if ((preNum !== num) && (firstNum !== num)) {
            newNums.push(num);
        }
        preNum = num;
    }
    nums = preNum;
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

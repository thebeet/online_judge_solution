/**
 * @param {number[]} nums
 * @param {number} m
 * @return {number}
 */
var splitArray = function(nums, m) {
    let sum = 0;
    let max = nums[0];
    let N = nums.length;
    for (let num of nums) {
        sum += num;
        max = Math.max(max, num);
    }
    let lo = max - 1;
    let hi = sum;
    
    let test = (splitSum) => {
        let count = 1;
        let sum = 0;
        let maxSum = 0;
        for (let num of nums) {
            if (num + sum > splitSum) {
                maxSum = Math.max(maxSum, sum);
                count += 1;
                sum = num;
            } else {
                sum += num;
            }
        }
        maxSum = Math.max(maxSum, sum);
        return {
            count,
            maxSum
        };
    };
    let result = sum;
    while (lo + 1 < hi) {
        let mid = Math.floor((lo + hi) / 2);
        let temp = test(mid);
        if (temp.count > m) {
            lo = mid;
        } else {
            hi = mid;
            result = Math.min(result, temp.maxSum);
        }
    }
    return result;
};


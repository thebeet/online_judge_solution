/**
 * @param {number[][]} nums
 * @return {number[]}
 */
var smallestRange = function(nums) {
    let result = {
        start: -1000000,
        end: 1000000,
        length: 2000000
    };
    let K = nums.length;
    let coverage = [];
    let coverageCount = 0;
    let position = [];
    for (let i = 0; i < K; i++) {
        coverage.push(0);
        position.push(0);
    }
    let countOfFinishList = 0;
    let queue = [];
    let queueStart = 0;
    let currentWindow = null;
    while (countOfFinishList < K) {
        let minimalList = -1;
        let minimalNumber = 10000000;
        for (let i = 0; i < K; ++i) {
            if (position[i] < nums[i].length) {
                if (minimalNumber > nums[i][position[i]]) {
                    minimalNumber = nums[i][position[i]];
                    minimalList = i;
                } 
            }
        }
        if (currentWindow === null) {
            currentWindow = {
                start: minimalNumber,
                end: minimalNumber,
                length: 0
            };
        } else {
            currentWindow.end = minimalNumber;
        }
        position[minimalList] += 1;
        if (position[minimalList] === nums[minimalList].length) {
            countOfFinishList += 1;
        }
        if (coverage[minimalList] === 0) {
            coverageCount += 1;
        }
        coverage[minimalList] += 1;
        queue.push({value: minimalNumber, list: minimalList});
        while (coverage[queue[queueStart].list] > 1) {
            coverage[queue[queueStart].list] -= 1;
            queueStart += 1;
        }
        currentWindow.start = queue[queueStart].value;
        currentWindow.length = currentWindow.end - currentWindow.start;
        if ((coverageCount === K) && (currentWindow.length < result.length)) {
            result = {
                start: currentWindow.start,
                end: currentWindow.end,
                length: currentWindow.length
            };
        }
    }
    return [result.start, result.end];
};

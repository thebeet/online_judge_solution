/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let N = height.length;
    let currentHeight = 0;
    let result = 0;
    let pending = 0;
    for (let i = 0; i < N; i++) {
        if (height[i] >= currentHeight) {
            currentHeight = height[i];
            result += pending;
            pending = 0;
        } else {
            pending += currentHeight - height[i];
        }
    }
    pending = 0;
    currentHeight = 0;
    for (let i = N - 1; i >= 0; i--) {
        if (height[i] > currentHeight) {
            currentHeight = height[i];
            result += pending;
            pending = 0;
        } else {
            pending += currentHeight - height[i];
        }
    }
    return result;
};

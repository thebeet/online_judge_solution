/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function(arr) {
    let stack = [];
    stack.push(-1);
    for (let number of arr) {
        let m = Math.max(number, stack[stack.length - 1]);
        while (stack[stack.length - 1] > number) {
            stack.pop();
        }
        stack.push(m);
    }
    return stack.length - 1;
};

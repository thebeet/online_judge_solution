/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    if (matrix.length === 0) return false;
    if (matrix[0].length === 0) return false;
    if (matrix[0][0] > target) return false;
    if (matrix[0][0] === target) return true;
    let n = matrix.length;
    let m = matrix[0].length;
    let lo = 0;
    let hi = n;
    while (lo + 1 < hi) {
        let mid = Math.floor((lo + hi) / 2);
        if (matrix[mid][0] > target) {
            hi = mid;
        } else if (matrix[mid][0] < target) {
            lo = mid;
        } else {
            return true;
        }
    }

    let lo2 = 0;
    let hi2 = m;
    while (lo2 + 1 < hi2) {
        let mid2 = Math.floor((lo2 + hi2) / 2);
        if (matrix[lo][mid2] > target) {
            hi2 = mid2;
        } else if (matrix[lo][mid2] < target) {
            lo2 = mid2;
        } else {
            return true;
        }
    }
    return false;
};

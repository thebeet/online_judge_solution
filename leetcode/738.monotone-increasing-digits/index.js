/**
 * @param {number} N
 * @return {number}
 */
var monotoneIncreasingDigits = function(N) {
    let result = [0];
    let last = () => {
        return result[result.length - 1];
    };
    let flag = false;
    for (let c of N.toString()) {
        if (flag) {
            result.push(9);
        } else {
            if (last() <= c) {
                result.push(c);
            } else {
                for (let j = result.length - 1; j >= 0; j--) {
                    result[j] -= 1;
                    if (result[j - 1] > result[j]) {
                        result[j] = 9;
                    } else {
                        break;
                    }
                }
                flag = true;
                result.push(9);
            }
        }
    }
    return parseInt(result.join(''), 10);
};

console.log(monotoneIncreasingDigits(10));

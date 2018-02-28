/**
 * @param {number[]} nums
 * @return {number}
 */
var maxCoins = function(nums) {
    let paddingNums = [1].concat(nums).concat([1]);
    let N = paddingNums.length;
    let dp = {};
    let getDp = (x, y) => {
        if (x in dp) {
            if (y in dp[x]) {
                
            } else {
                dp[x][y] = -1;
            }
        } else {
            dp[x] = {};
            dp[x][y] = -1;
        }
        return dp[x][y];
    }
    
    let calc = (start, end) => {
        if (getDp(start, end) === -1) {
            dp[start][end] = 0;
            if (start + 2 === end) {
                dp[start][end] = paddingNums[start] * paddingNums[start + 1] * paddingNums[start + 2];
            } else {
                for (let i = start + 1; i < end; i++) {
                    dp[start][end] = Math.max(dp[start][end],
                            calc(start, i) + calc(i, end) + paddingNums[i] * paddingNums[start] * paddingNums[end]
                    );
                }               
            }
        }
        return dp[start][end];
    };
    return calc(0, N - 1);
};

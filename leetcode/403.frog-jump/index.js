/**
 * @param {number[]} stones
 * @return {boolean}
 */
var canCross = function(stones) {
    let N = stones.length;
    let dp = [];
    let stoneMap = {};
    let k = 0;
    for (let stone of stones) {
        dp.push({});
        stoneMap[stone] = k;
        k += 1;
    }
    let calc = (position, preJump) => {
        if (position === N - 1) {
            return true;
        }
        if (!(preJump in dp[position])) {
            dp[position][preJump] = false;
            for (let i = Math.max(1, preJump - 1); i <= preJump + 1; i++) {
                let nextPosition = stones[position] + i;
                if (nextPosition in stoneMap) {
                    nextPosition = stoneMap[nextPosition];
                    if (calc(nextPosition, i)) {
                        dp[position][preJump] = true;
                        return true;
                    }
                }
            }
        }
        return dp[position][preJump];
    };
    return calc(0, 0);
};

/**
 * @param {number[]} boxes
 * @return {number}
 */
var removeBoxes = function(boxes) {
    let N = boxes.length;
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
        if (start > end) return 0;
        if (getDp(start, end) === -1) {
            let flag = true;
            for (let i = start + 1; i <= end; i++) {
                if (boxes[i] !== boxes[start]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                dp[start][end] = (end - start + 1) * (end - start + 1);
            } else {
                if (boxes[start] === boxes[end]) {
                    let lenLeft = 0;
                    let sumLeft = 0;
                    let preLeft = start + 1;
                    for (let i = start; i <= end; i++) {
                        if (boxes[i] === boxes[start]) {
                            lenLeft += 1;
                            sumLeft += calc(preLeft, i - 1);
                            preLeft = i + 1;
                            let lenRight = 0;
                            let sumRight = 0;
                            let preRight = end - 1;
                            for (let j = end; j > i; j--) {
                                if (boxes[j] === boxes[start]) {
                                    lenRight += 1;
                                    sumRight += calc(j + 1, preRight);
                                    preRight = j - 1;

                                    dp[start][end] = Math.max(dp[start][end], sumLeft + sumRight + calc(i + 1, j - 1) + (lenLeft + lenRight) * (lenLeft + lenRight));
                                }

                            }
                        }
                    }
                    let nStart = start + 1;
                    let nEnd = end - 1;
                    while (boxes[nStart] === boxes[start]) {
                        nStart += 1;
                    }
                    while (boxes[nEnd] === boxes[start]) {
                        nEnd -= 1;
                    }
                    let len = (end - nEnd) + (nStart - start); 
                    dp[start][end] = Math.max(dp[start][end], calc(nStart, nEnd) + len * len);
                }
                
                for (let i = start + 1; i <= end; i++) {
                    if (boxes[i] !== boxes[i - 1]) {
                        dp[start][end] = Math.max(dp[start][end], calc(start, i - 1) + calc(i, end));
                    }
                }
                
            }
        }
        return dp[start][end];
    };
    return calc(0, N - 1);
};

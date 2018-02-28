/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
    let rank = [];
    let map = {};
    let N = heights.length;
    for (let i = 0; i < heights.length; i++) {
        rank.push({height: heights[i], index: i});
    }
    rank.sort((a, b) => {
       if (a.height < b.height) return 1; 
       if (a.height > b.height) return -1; 
       return 0;
    });
    let result = 0;
    for (let heightRank of rank) {
        let i = heightRank.index;
        let currentHeight = heightRank.height;
        map[i] = {
            lo: i,
            hi: i
        };
        while (map[i].lo > 0) {
            if (heights[map[i].lo - 1] >= currentHeight) {
                map[i].lo = map[i].lo - 1;
                if (map[i].lo in map) {
                    map[i].lo = map[map[i].lo].lo;
                } else {
                    if (heights[map[i].lo] === currentHeight) {
                        map[map[i].lo] = map[i];
                    }
                }
            } else {
                break;
            }
        }
        while (map[i].hi < N - 1) {
            if (heights[map[i].hi + 1] >= currentHeight) {
                map[i].hi = map[i].hi + 1;
                if (map[i].hi in map) {
                    map[i].hi = map[map[i].hi].hi;
                } else {
                    if (heights[map[i].hi] === currentHeight) {
                        map[map[i].hi] = map[i];
                    }
                }
            } else {
                break;
            }
        }
        result = Math.max(result, currentHeight * (map[i].hi - map[i].lo + 1));
    }
    return result;
};

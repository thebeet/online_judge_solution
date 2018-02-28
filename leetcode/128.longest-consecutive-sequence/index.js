/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    let map = {};
    let result = 0;
    let findRoot = (node) => {
        if (node.next !== node) {
            node.next = findRoot(node.next);
        } 
        return node.next;
    };
    for (let num of nums) {
        if (!(num in map)) {
            map[num] = {
                next: null,
                max: num,
                min: num
            };
            map[num].next = map[num];
        }
        let preNum = num - 1;
        let nextNum = num + 1;
        if (preNum in map) {
            map[preNum] = findRoot(map[preNum]);
            map[num].next.min = Math.min(map[num].next.min, map[preNum].next.min);
            if (map[preNum].max < map[num].max) {
                map[preNum].next = map[num];
            }
        }

        if (nextNum in map) {
            map[nextNum] = findRoot(map[nextNum]);
            map[nextNum].next.min = Math.min(map[nextNum].next.min, map[num].next.min);
            map[num].next = map[nextNum];
        }
        map[num] = findRoot(map[num]);
        result = Math.max(result, map[num].next.max - map[num].next.min + 1);
    }
    return result;
};

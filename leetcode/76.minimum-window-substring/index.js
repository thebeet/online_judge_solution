/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    let tMap = {};
    for (let c of t) {
        if (!(c in tMap)) {
            tMap[c] = 1;
        } else {
            tMap[c] += 1;
        }
    }
    let result = "";
    let matchCount = 0;
    let lo = 0;
    for (let i = 0; i < s.length; i++) {
        let c = s[i];
        if (c in tMap) {
            if (tMap[c] > 0) {
                matchCount += 1;
            }
            tMap[c] -= 1;
            if (matchCount >= t.length) {
                for (; lo < i; lo++) {
                    let c = s[lo];
                    if (c in tMap) {
                        if (tMap[c] < 0) {
                            tMap[c] += 1;
                        } else {
                            break;
                        }
                    }
                }
                if ((result === "") || (result.length > i - lo + 1)) {
                    result = s.substr(lo, i - lo + 1);
                }
            }
        }
    }
    return result;
};

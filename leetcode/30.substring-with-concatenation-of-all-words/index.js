/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
    let wordMap = {};
    let N = words.length;
    for (let word of words) {
        if (!(word in wordMap)) {
            wordMap[word] = 1;
        } else {
            wordMap[word] += 1;
        }
    }
    words = [];
    for (let word in wordMap) {
        words.push(word);
    }
    
    let n = words.length;
    if (n === 0) return null;
    let m = words[0].length;
    let matchs = [];
    for (let i = 0; i < s.length; i++) {
        if (i + m > s.length) {
            matchs.push(-1);
        } else {
            let subs = s.substr(i, m);
            let match = -1;
            for (let j = 0; j < n; ++j) {
                if (words[j] === subs) {
                    match = j;
                    break;
                }
            }
            matchs.push(match);
        }
    }
    let results = [];
    for (let i = 0; i + m * N <= s.length; i++) {
        let flags = {};
        let result = true;
        for (let j = i; j < i + m * N; j += m) {
            if (matchs[j] === -1) {
                result = false;
                break;
            }
            if (matchs[j] in flags) {
                flags[matchs[j]] += 1;
                if (flags[matchs[j]] > wordMap[words[matchs[j]]]) {
                    result = false;
                    break;
                }
            } else {
                flags[matchs[j]] = 1;
            }
        }
        if (result) {
            results.push(i);
        }
    }
    return results;
};

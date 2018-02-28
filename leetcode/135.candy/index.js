/**
 * @param {number[]} ratings
 * @return {number}
 */
var candy = function(ratings) {
    let N = ratings.length;
    let candys = [];
    let ratingsRank = [];
    for (let i = 0; i < ratings.length; i++) {
        if ((i > 0) && (ratings[i] === ratings[i - 1])) {
            ratingsRank[ratingsRank.length - 1].right = i + 1;
            ratingsRank[ratingsRank.length - 1].length += 1;
        } else {
            ratingsRank.push({rating: ratings[i], index: i, left: i - 1, right: i + 1, length: 1});
        }
        candys.push({candy: 0});
    }
    ratingsRank.sort(function (a, b) {
        if (a.rating < b.rating) return -1;
        if (a.rating > b.rating) return 1;
        return 0;
    });
    for (let ratingRankItem of ratingsRank) {
        let left = ratingRankItem.left;
        let right = ratingRankItem.right;
        let maxCandy = 1;
        for (let i = left + 1; i < right; i++) {
            candys[i].candy = 1;
        }
        if (left >= 0) {
            candys[left + 1].candy = Math.max(candys[left + 1].candy, candys[left].candy + 1);
        }
        if (right < N) {
            candys[right - 1].candy = Math.max(candys[right - 1].candy, candys[right].candy + 1);
        }
    }
    let result = 0;
    for (let candyItem of candys) {
        result += candyItem.candy;
    }
    return result;
};

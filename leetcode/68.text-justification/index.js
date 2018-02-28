/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function(words, maxWidth) {
    let result = [];
    let currentWords = [];
    let currentLength = -1;
    let currentWordLength = 0;
    for (let word of words) {
        if (currentLength + 1 + word.length > maxWidth) {
            let currentLine = '';
            if (currentWords.length > 1) {
                let spaceLength = (maxWidth - currentWordLength) / (currentWords.length - 1);
                let spaceLengthRest = (maxWidth - currentWordLength) % (currentWords.length - 1);
                currentLine += currentWords[0];
                for (let i = 1; i < currentWords.length; i++) {
                    currentLine += ' '.repeat(spaceLength + ((i <= spaceLengthRest) ? 1 : 0));
                    currentLine += currentWords[i];
                }
            } else {
                currentLine = currentWords[0] + ' '.repeat(maxWidth - currentWordLength);
            }
            result.push(currentLine);
            currentWords = [];
            currentLength = -1;
            currentWordLength = 0;
        }
        currentWords.push(word);
        currentWordLength += word.length;
        currentLength += (1 + word.length);
    }
    if (currentWords.length > 0) {
        let lastLine = currentWords.join(' ');
        lastLine += ' '.repeat(maxWidth - lastLine.length);
        result.push(lastLine);
    }
    return result;
};

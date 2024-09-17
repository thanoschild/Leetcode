/**
 * @param {string} s1
 * @param {string} s2
 * @return {string[]}
 */
var uncommonFromSentences = function(s1, s2) {
    const words = (s1 + " " + s2).split(" ");
   
    const wordCount = new Map();
    
    words.forEach(word => {
        wordCount.set(word, (wordCount.get(word) || 0) + 1);
    });

    return Array.from(wordCount.entries())
                .filter(([word, count]) => count === 1)
                .map(([word]) => word);
};
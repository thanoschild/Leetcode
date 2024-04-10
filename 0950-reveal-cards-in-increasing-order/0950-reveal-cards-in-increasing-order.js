/**
 * @param {number[]} deck
 * @return {number[]}
 */
var deckRevealedIncreasing = function(deck) {
    const n = deck.length;
    deck.sort((a, b) => a - b);
    const queue = Array.from(Array(n), (_, i) => i);
    const ans = new Array(n).fill(0);

    for (let i = 0; i < n; i++) {
        ans[queue.shift()] = deck[i];
        if (queue.length > 0) {
            queue.push(queue.shift());
        }
    }

    return ans;
};
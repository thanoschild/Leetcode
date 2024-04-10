class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int n = deck.length;
        Arrays.sort(deck);
        Queue<Integer> pq = new LinkedList<>();
        int[] ans = new int[n];

        for(int i = 0; i<n; i++) pq.add(i);

        for(int i = 0; i<n; i++) {
            ans[pq.poll()] = deck[i];
            pq.add(pq.poll());
        }

        return ans;
    }
}
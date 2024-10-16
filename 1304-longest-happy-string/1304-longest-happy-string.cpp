class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        string ans = "";

        while(pq.size() > 1) {
            pair<int, char> one = pq.top();
            pq.pop();
            pair<int, char> two = pq.top();
            pq.pop();

            if(one.first >= 2) {
                ans += one.second;
                ans += one.second;
                one.first -= 2;
            } else {
                ans += one.second;
                one.first--;
            }

            if(two.first >= 2 && two.first > one.first) {
                ans += two.second;
                ans += two.second;
                two.first -= 2;
            } else {
                ans += two.second;
                two.first--;
            }

            if(one.first > 0) pq.push(one);
            if(two.first > 0) pq.push(two);
        }

        if(pq.empty()) return ans;
        if(pq.top().first >= 2) {
            ans += pq.top().second;
            ans += pq.top().second;
        } else {
            ans += pq.top().second;
        }

        return ans;
    } 
};
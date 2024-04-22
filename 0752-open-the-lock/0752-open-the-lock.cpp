class Solution {
public:
    vector<string> possible_ways(string str) {
        vector<string> ways;
        for(int i = 0; i<4; i++) {
            string curr = str;
            if(curr[i] == '9') curr[i] = '0';
            else curr[i] = curr[i] + 1;
            ways.push_back(curr);

            curr = str;
            if(curr[i] == '0') curr[i] = '9';
            else curr[i] = curr[i] - 1;
            ways.push_back(curr);
        }

        return ways;
    }

    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;
        unordered_set<string> check(deadends.begin(), deadends.end()), visited;
        queue<string> pq;
        pq.push("0000");
        int ans = 0;

        while(!pq.empty()) {
            int n = pq.size();
            for(int i = 0; i<n; i++) {
                string curr = pq.front();
                pq.pop();

                if(curr == target) return ans;
                if(visited.count(curr) || check.count(curr)) continue;

                vector<string> ways = possible_ways(curr);
                for(string s : ways) pq.push(s);
                visited.insert(curr);
            }
            ans++;
        }

        return -1;
    }
};
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = routes.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i<n; i++) {
            for(auto it : routes[i]) {
                mp[it].push_back(i);
            }
        }

        queue<int> pq;
        pq.push(source);
        unordered_map<int, int> busStop, bus;
        busStop[source] = 1;
        int buses = 0;
        while(!pq.empty()) {
            int k = pq.size();
            while(k--) {
                int t = pq.front();
                pq.pop();

                if(t == target) return buses;

                for(auto it : mp[t]) {
                    if(!bus[it]) {
                        bus[it] = 1;
                        for(auto stops : routes[it]) {
                            if(!busStop[stops]) {
                                pq.push(stops);
                                busStop[stops] = 1;
                            }
                        }
                    }
                }
            }
            buses++;
        }

        return -1;
    }
};
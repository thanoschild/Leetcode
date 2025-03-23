#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;
    int findWays(vector<vector<pair<ll,ll>>> &edges, int n) {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            ll d = t.first;
            ll x = t.second;
            if(dist[x] < d) continue;
            for(auto it : edges[x]){
                if(dist[it.first] > dist[x] + it.second){
                    dist[it.first] = dist[x] + it.second;
                    ways[it.first] = ways[x];
                    pq.push({dist[it.first], it.first});
                }
                else if(dist[it.first] == dist[x] + it.second){
                    ways[it.first] = (ways[x] + ways[it.first])%mod;
                }
            }
        }
        
        return ways[n-1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>> edges(n);
        for(auto it : roads) {
            edges[it[0]].push_back({it[1], it[2]});
            edges[it[1]].push_back({it[0], it[2]});
        }

        return findWays(edges, n);
    }
};
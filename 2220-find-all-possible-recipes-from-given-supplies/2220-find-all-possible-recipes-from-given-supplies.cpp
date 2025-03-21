class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, vector<string>> edges;
        unordered_map<string, int> indegree;

        for(int i = 0; i<n; i++) {
            indegree[recipes[i]] = ingredients[i].size();
            for(string ingredient : ingredients[i]) {
                edges[ingredient].push_back(recipes[i]);
            }
        }

        queue<string> pq;
        for(string supply : supplies) {
            pq.push(supply);
        }

        vector<string> ans;
        while(!pq.empty()) {
            string item = pq.front();
            pq.pop();

            if(indegree.find(item) != indegree.end()) {
                ans.push_back(item);
            }

            for(string recipe : edges[item]) {
                indegree[recipe]--;
                if(indegree[recipe] == 0) pq.push(recipe);
            }
        }

        return ans;
    }
};
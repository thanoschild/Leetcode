class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> pq;
        for(int i = 0; i<numCourses; i++) {
            if(indegree[i] == 0) pq.push(i);
        }
        
        int count = 0;
        while(!pq.empty()) {
            int t = pq.front();
            pq.pop();
            count++;
            for(int course : adj[t]) {
                indegree[course]--;
                if(indegree[course] == 0) pq.push(course);
            }
        }

        return count == numCourses;
    }
};
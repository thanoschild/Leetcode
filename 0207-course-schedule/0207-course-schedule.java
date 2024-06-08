class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i<numCourses; i++) {
            adj.add(new ArrayList<>());
        }
        int[] indegree = new int[numCourses];

        for(int[] it : prerequisites) {
            adj.get(it[1]).add(it[0]);
            indegree[it[0]]++;
        }

        Queue<Integer> pq = new LinkedList<>();
        for(int i = 0; i<numCourses; i++) {
            if(indegree[i] == 0) pq.add(i);
        }

        int count = 0;
        while(!pq.isEmpty()) {
            int t = pq.poll();
            count++;

            for(int course : adj.get(t)) {
                indegree[course]--;
                if(indegree[course] == 0) pq.add(course);
            }
        }

        return count == numCourses;
    }
}
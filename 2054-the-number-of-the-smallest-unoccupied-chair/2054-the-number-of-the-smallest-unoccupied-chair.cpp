class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        set<int> st;

        int idx = 0, arrivalTarget = times[targetFriend][0];
        sort(times.begin(), times.end());

        for(auto it : times) {
           int arrivalTime = it[0], leavingTime = it[1];
           int currentSeat;

           while(!pq.empty() && pq.top().first <= arrivalTime) {
               st.insert(pq.top().second);
               pq.pop();
           }

           if(!st.empty()) {
              currentSeat = *st.begin();
              st.erase(st.begin());
           }
           else {
             currentSeat = idx;
             idx++;
           }

           if(arrivalTime == arrivalTarget) return currentSeat;
           pq.push({leavingTime, currentSeat});
        }

        return -1;
    }
};
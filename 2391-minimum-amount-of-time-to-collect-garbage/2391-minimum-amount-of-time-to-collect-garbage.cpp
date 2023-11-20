class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        vector<char> c = {'G', 'M', 'P'};
        for(char x : c){
            int time = 0, lastpick = 0;
            for(int i = 0; i<garbage.size(); i++){
                int cnt = count(garbage[i].begin(), garbage[i].end(), x);
                if(cnt > 0){
                    time += cnt;
                    lastpick = i;
                }
                if(i < travel.size()) time += travel[i];
            }
            for(int j = garbage.size() - 2; j>=lastpick; j--){
                time -= travel[j];
            }
            
            ans += time;
        }
        
        return ans;
    }
};
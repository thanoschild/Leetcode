class MyCalendarTwo {
public:
    map<int, int> mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start] += 1;
        mp[end] -= 1;

        int count = 0;
        for(auto it : mp) {
            count += it.second;
            if(count > 2) {
                mp[start] -= 1;
                if(mp[start] == 0) mp.erase(start);
                mp[end] += 1;
                if(mp[end] == 0) mp.erase(end);
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
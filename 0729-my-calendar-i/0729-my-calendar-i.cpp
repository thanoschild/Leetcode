class MyCalendar {
public:
    vector<pair<int,int>> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it : events) {
            if(max(start, it.first) < min(end, it.second)) return false;
        }
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
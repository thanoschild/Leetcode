class NumberContainers {
public:
    map<int,int>mp1;
    map<int,set<int>>mp2;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp1.find(index)==mp1.end()){
            mp1[index]=number;
            mp2[number].insert(index);
        }
        else{
            mp2[mp1[index]].erase(index);
            mp1[index]=number;
            mp2[number].insert(index);
        }
    }
    
    int find(int number) {
        if(mp2.find(number)==mp2.end() || mp2[number].size()==0)return -1;
        for(auto it : mp2[number]){
           return it;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
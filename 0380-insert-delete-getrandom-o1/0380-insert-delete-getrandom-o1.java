class RandomizedSet {
    java.util.Random rand = new java.util.Random();
    HashMap<Integer, Integer> mp = new HashMap<>();
    List<Integer> v = new ArrayList<>();
    public RandomizedSet() {
        
    }
    
    public boolean insert(int val) {
        if(mp.containsKey(val)) return false;
        v.add(val);
        mp.put(val, v.size() - 1);
        return true;
    }
    
    public boolean remove(int val) {
        if(!mp.containsKey(val)) return false;
        int last = v.get(v.size() - 1);
        mp.put(last, mp.get(val));
        v.set(mp.get(last), last);
        mp.remove(val);
        v.remove(v.size() - 1);
        return true;
    }
    
    public int getRandom() {
        return v.get(rand.nextInt(v.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
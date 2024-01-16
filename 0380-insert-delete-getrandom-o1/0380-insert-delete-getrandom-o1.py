class RandomizedSet(object):

    def __init__(self):
        self.mp = {}
        self.arr = []


    def insert(self, val):
        if val in self.mp: return False
        self.mp[val] = len(self.arr)
        self.arr.append(val)
        return True
        

    def remove(self, val):
        if not val in self.mp: return False
        last = self.arr[-1]
        self.mp[last] = self.mp[val]
        self.arr[self.mp[last]] = last
        self.arr.pop()
        self.mp.pop(val)
        return True
        

    def getRandom(self):
        return random.choice(self.arr)
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
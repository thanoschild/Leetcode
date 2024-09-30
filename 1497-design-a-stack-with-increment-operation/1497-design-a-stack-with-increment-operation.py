class CustomStack(object):

    def __init__(self, maxSize):
        self.stack = []
        self.len = maxSize
        

    def push(self, x):
        if len(self.stack) < self.len:
            self.stack.append(x)

        
    def pop(self):
        if self.stack:
            return self.stack.pop()
        return -1
        

    def increment(self, k, val):
        for i in range(min(k, len(self.stack))):
            self.stack[i] += val
        


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
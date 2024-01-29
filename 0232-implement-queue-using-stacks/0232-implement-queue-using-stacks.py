class MyQueue(object):

    def __init__(self):
        self.st1 = []
        self.st2 = []


    def push(self, x):
        while self.st1:
            self.st2.append(self.st1.pop())
        self.st2.append(x)
        while self.st2:
            self.st1.append(self.st2.pop())
        

    def pop(self):
        return self.st1.pop()
        

    def peek(self):
        return self.st1[-1]
        

    def empty(self):
        return not self.st1
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
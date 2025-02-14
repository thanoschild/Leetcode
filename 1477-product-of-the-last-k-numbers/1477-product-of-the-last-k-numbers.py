class ProductOfNumbers(object):
  
    def __init__(self):
        self.prefix = [1]
        

    def add(self, num):
        if num > 0:
            self.prefix.append(self.prefix[-1] * num)
        else:
            self.prefix = [1]
        

    def getProduct(self, k):
        n = len(self.prefix)
        return self.prefix[-1] / self.prefix[n - 1 - k] if k < n else 0
        


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)
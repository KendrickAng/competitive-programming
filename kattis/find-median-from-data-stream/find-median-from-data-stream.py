from sortedcontainers import SortedList

class MedianFinder:

    def __init__(self):
        self.arr = SortedList()

    def addNum(self, num: int) -> None:
        self.arr.add(num)

    def findMedian(self) -> float:
        n = len(self.arr)
        if n % 2 == 0: # even
            return (self.arr[(n-1)//2] + self.arr[n//2]) / 2
        else:
            # odd
            return self.arr[n//2]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
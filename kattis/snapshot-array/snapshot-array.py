from sortedcontainers import SortedDict

class SnapshotArray:

    def __init__(self, length: int):
        self.snap_id = 0
        self.arr = [[(self.snap_id, 0)] for _ in range(length)]

    def set(self, index: int, val: int) -> None:
        self.arr[index].append((self.snap_id, val))

    def snap(self) -> int:
        prev = self.snap_id
        self.snap_id += 1
        return prev

    def get(self, index: int, snap_id: int) -> int:
        # binary search for first snap id less than or equal to snap_id
        arr = self.arr[index]
        lo = 0
        hi = len(arr) - 1
        last_val = None
        while lo <= hi:
            mid = (lo + hi) // 2
            sid, val = arr[mid]
            
            if sid == snap_id or sid < snap_id:
                # go right
                last_val = val
                lo = mid + 1
            elif sid > snap_id:
                # go left
                hi = mid - 1
        return last_val

# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)

"""
Array of bbsts
snap_id -> initalises to -1
init -> 
set -> arr[index][snap_id] = val
snap -> increments snap_id
get -> arr[index][predecessor(snap_id)]
"""
def minTime(machines, goal):
    def check_cond(days):
        return sum([days // a for a in machines]) >= goal
    machines.sort()
    n = len(machines)
    hi = goal // (1/machines[-1] * n)    # max num of days
    lo = goal // (1/machines[0] * n)    # min num of days
    #print("{0} {1}".format(hi, lo))
    ans = -1
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if check_cond(mid):
            ans = mid
            #print(ans)
            hi = mid - 1
        else:
            lo = mid + 1
    return int(ans)

print(minTime([2,3], 5))
print(minTime([1,3,4], 10))
print(minTime([4,5,6], 12))
import datetime
import math
import sys

merit = 0
demerit = 0

def parseDate(s):
    return datetime.date(int(s[0:4]), int(s[4:6]), int(s[6:8]))

def printDatePts():
    global curr, merit, demerit
    dateStr = curr.strftime("%Y-%m-%d")
    if merit == 0 and demerit == 0:
        print(f"{dateStr} No merit or demerit points.")
    elif merit == 0:
        print(f"{dateStr} {demerit} demerit point(s).")
    else:
        print(f"{dateStr} {merit} merit point(s).")

curr = parseDate(input())
printDatePts()

def applyMerit(currDate, nxtOffense):
    global merit, curr
    # luckily, datetime is immutable
    # must have no demerit points to get merit points
    if demerit > 0: return

    while True:
        currDate = currDate.replace(year=currDate.year+2)

        if (currDate > nxtOffense) or merit >= 5: break

        merit = min(merit+1, 5)
        curr = currDate
        printDatePts()
    # printDatePts()

def applyDemeritReduction(currDate, nxtOffense):
    global demerit, curr
    if demerit == 0: return

    while True:
        currDate = currDate.replace(year=currDate.year+1)

        if currDate > nxtOffense or demerit <= 0: break

        if (demerit / 2) > 2:
            demerit = max(demerit//2, 0)
        else:
            demerit = max(demerit-2, 0)
        curr = currDate
        printDatePts()
    
    # printDatePts()

def applyDemeritPts(currDate, nxtOffense, demerits):
    global merit, demerit, curr

    curr = nxtOffense
    demerit += demerits
    if merit > 0:
        if demerit > (merit * 2):
            demerit -= merit * 2
            merit = 0
        else:
            merit -= math.ceil(demerit / 2)
            demerit = 0
    printDatePts()

for line in sys.stdin:
    # print(line)
    rawDate, demerits = line.split()
    nxtOffense = parseDate(rawDate)
    demerits = int(demerits)

    applyDemeritReduction(curr, nxtOffense)
    applyMerit(curr, nxtOffense)
    applyDemeritPts(curr, nxtOffense, demerits)

# all offenses done, now wait for demerits to diminish
while demerit > 0:
    curr = curr.replace(year=curr.year+1)
    if (demerit / 2) > 2:
        demerit = max(demerit//2, 0)
    else:
        demerit = max(demerit-2, 0)
    printDatePts()

# all offenses done, now just accumulate merits
while merit < 5:
    curr = curr.replace(year=curr.year + 2)
    merit += 1
    printDatePts()
import datetime
import calendar
from collections import defaultdict

base = datetime.date(2009, 12, 19)

offset = defaultdict(int)
offset[9998] = 0 # offset[i] = days from 01/01/9999 (inclusive) to 01/01/i (exclusive)
for year in range(9999, 100000):
    if calendar.isleap(year):
        offset[year] += offset[year-1] + 366
    else:
        offset[year] += offset[year-1] + 365

while True:
    a, b, c = map(int, input().split())
    if (a == 0 and b == 0 and c == 0): break

    if c <= 9999 and (datetime.date(c, b, a) < base):
        print(-1)
    elif c <= 9999:
        print((datetime.date(c, b, a) - base).days)
    else:
        one = (datetime.date(9999, 1, 1) - base).days
        two = offset[c]
        if calendar.isleap(c):
            three = (datetime.date(2021, 1, 1) - datetime.date(2020, b, a)).days # 2020 is leap
        else:
            three = (datetime.date(2, 1, 1) - datetime.date(1, b, a)).days # 1 is not leap
        print(one + two - three)


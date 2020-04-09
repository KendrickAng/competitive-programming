#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the minimumBribes function below.
def minimumBribes(q):
    # make it more intuitive
    q = [i - 1 for i in q]

    bribes = 0
    # idx is original position, person is current person at the idx
    for idx, person in enumerate(q):
        if person - idx > 2:
            print('Too chaotic')
            return

        # look from one in front of curr pos to one in front of original pos
        # idx-1+1 cuz range must stop at (idx-1)
        for i in range(max(0, person - 1), idx - 1 + 1):
            if q[i] > person:
                bribes += 1
    print(bribes)


if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)

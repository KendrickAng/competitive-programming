#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumBribes function below.
def minimumBribes(q):
    def count_inversions(q):
        def _merge(q, temp_arr, left, mid, right):
            """
            Merges elements from q to temp_arr, counting inversions in the process.
            """
            inv_count = 0
            left_ptr = left
            right_ptr = mid + 1
            temp_ptr = left
            while left_ptr <= mid and right_ptr <= right:
                if q[left_ptr] <= q[right_ptr]:
                    # no inversion, just put to final array and inc ptrs
                    temp_arr[temp_ptr] = q[left_ptr]
                    left_ptr += 1
                else:
                    # inversion found, also copy from right arr to final arr
                    temp_arr[temp_ptr] = q[right_ptr]
                    right_ptr += 1
                    inv_count += (mid - left_ptr + 1) # add number of elements from idx i to j
                temp_ptr += 1
            # copy remaining items
            while left_ptr <= mid:
                temp_arr[temp_ptr] = q[left_ptr]
                temp_ptr += 1
                left_ptr += 1
            while right_ptr <= right:
                temp_arr[temp_ptr] = q[right_ptr]
                right_ptr += 1
                temp_ptr += 1
            # copy sorted array back
            for i in range(left, right + 1):
                q[i] = temp_arr[i]
            return inv_count

        def _merge_sort(q, temp_arr, left, right):
            """
            sorts the array from idx left to right and returns inversion count.
            """
            inv_count = 0
            if left < right:
                mid = (left + right) // 2
                inv_count += _merge_sort(q, temp_arr, left, mid)
                inv_count += _merge_sort(q, temp_arr, mid + 1, right)
                inv_count += _merge(q, temp_arr, left, mid, right)
            return inv_count

        temp_arr = [0] * len(q)
        return _merge_sort(q, temp_arr, 0, len(q) - 1)

    # bribing occurs if difference > 3
    for i in range(len(q)):
        if q[i] - i > 3:
            print("Too chaotic")
            return
    # no bribing, count inversions
    print(count_inversions(q))

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)

# Problem link : https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-i/description/?envType=problem-list-v2&envId=bit-manipulation

from typing import List

def minimumSubarrayLength(nums: List[int], k: int) -> int:
    n = len(nums)

    # initialize `minLen` to a value greater than any possible subarray length (n + 1).
    # this will be used to keep track of the minimum subarray length found.
    min_len = n + 1

    # to store the cumulative OR value of the current subarray being evaluated.
    curORVal = 0

    # outer loop to set the starting index `i` of the subarray
    for i in range(n):
        # reset cumulative OR value for each new starting index `i`
        curORVal = 0
        # inner loop to set the ending index `j` of the subarray
        for j in range(i, n):
            # update the cumulative OR value with the current element `nums[j]`
            curORVal |= nums[j]
            # check if the cumulative OR value is at least `k`
            if curORVal >= k:
                # update the minimum length `minLen` if the current subarray is shorter
                min_len = min(min_len, j+1-i)

    # if `minLen` is still equal to `n + 1`, no valid subarray was found, so return -1.
    # otherwise, return the minimum length of the special subarray found.            
    return min_len if min_len != n + 1 else -1

# nums = [1, 2, 3]
# k = 2

# nums = [2, 1, 8]
# k = 10

nums = [2, 24, 32, 1]
k = 22
print(minimumSubarrayLength(nums, k))
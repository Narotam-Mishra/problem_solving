
# Problem link : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/?envType=problem-list-v2&envId=bit-manipulation

def numberOfSteps(num: int) -> int:
    # edge case: If num is 0, return 0
    if not num:
        return 0
    
    # initialize the step counter
    res = 0

    # loop until num becomes 0
    while num > 0:
        # if num is odd, subtract 1
        # otherwise, if num is even, divide it by 2
        num = num - 1 if num & 1 else num >> 1
        res += 1

    # return the total number of steps taken
    return res

num = 123
print(numberOfSteps(num))

## Problem link : https://leetcode.com/problems/binary-gap/description/?envType=problem-list-v2&envId=bit-manipulation

def binaryGap(n: int) -> int:
    max_distance = 0
    last_pos = -1
    curr_pos = 0

    while n > 0:
        # check if the current bit is 1
        if n & 1:
            if last_pos != -1:
                # calculate the distance between the current and last 1
                max_distance = max(max_distance, curr_pos - last_pos)

            # update the position of the last 1    
            last_pos = curr_pos

        # shift right to process the next bit
        n = n >> 1
        # update current position 'currPos'
        curr_pos += 1

    # return maximum distance 'maxDistance'
    return max_distance

# num = 22

# num = 8

num = 5
print(binaryGap(num))

## Problem link : https://leetcode.com/problems/number-complement/?envType=problem-list-v2&envId=bit-manipulation

def findComplement(num: int) -> int:
    ## step 1: find the bit length of the number
    bit_length = num.bit_length()

    ## step 2: create a mask of the same length with all bits set to 1
    bit_mask = (1 << bit_length) - 1

    ## step 3: XOR the number with the mask to get the complement
    return num ^ bit_mask

# num = 5

num = 1
print(findComplement(num))
                
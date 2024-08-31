
# Problem link : https://leetcode.com/problems/number-of-1-bits/description/

def hammingWeight(n: int) -> int:
    # intialize setBits to 0
    setBits = 0

    # count the number of 1's in the binary representation of num
    while(n > 0):
        # increment if the least significant bit is 1
        setBits += n & 1

        # right shift num by 1 bit
        n = n >> 1

    # return count of setBits
    return setBits

num = 2147483645
print(hammingWeight(num))
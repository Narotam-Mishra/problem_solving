
# Problem link : https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/description/?envType=problem-list-v2&envId=bit-manipulation

def count_set_bits(num):
    setBits = 0
    # loop through each bit in num
    while num > 0:
        # check if the least significant bit is 1
        setBits += num & 1
        # shift the bits of num to the right to check the next bit
        num = num >> 1
    return setBits

def minChanges(n: int, k: int) -> int:
    # edge case: if k has any 1s in positions where n has 0s, return -1
    if (n & k) != k:
        return -1

    # count the number of 1s in n and k
    countOnesN = count_set_bits(n)
    countOnesK = count_set_bits(k)

    # if n has fewer 1s than k, it's impossible to change n to k
    if countOnesN < countOnesK:
        return - 1

    # calculate the XOR of n and k to identify differing bits
    xorVal = n ^ k

    # count the number of bits in the XOR value where n and k differ 
    # (this includes both 1->0 and 0->1 changes)
    differBits = count_set_bits(xorVal)

    # the minimum changes needed are the number of differing bits
    return differBits

n = 13
k = 4

# n = 21
# k = 21

# n = 14
# k = 13
print(minChanges(n, k))

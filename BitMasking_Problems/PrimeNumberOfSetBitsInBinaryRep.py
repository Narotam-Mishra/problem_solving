
## Problem link : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/?envType=problem-list-v2&envId=bit-manipulation

import math

def isPrime (n: int) -> bool:
    # corner case:
    if n <= 1:
        return False
    
    # check from 2 to sqrt(n)
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
        
    # if no divisors are found, n is prime
    return True

def countPrimeSetBits(left: int, right: int) -> int:
    # initialize counter for numbers with prime set bits
    cntPrimeSetBits = 0

    # iterate through all numbers in the range [left, right]
    for i in range(left, right+1):
        num = i
        setBits = 0

        # count the number of set bits (1s) in the binary representation of num
        while num > 0:
            # increment setBits if the least significant bit is 1
            setBits += num & 1
            # right shift num to check the next bit
            num = num >> 1

        # check if the number of set bits is prime
        if isPrime(setBits):
            # increment counter if setBits is prime
            cntPrimeSetBits += 1

    # return the total count of numbers with prime set bits
    return cntPrimeSetBits

# left = 6
# right = 10

left = 10
right = 15
print(countPrimeSetBits(left, right))
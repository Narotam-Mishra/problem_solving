
# Problem link : https://leetcode.com/problems/power-of-four/

def isPowerOfFour(n: int) -> bool:
    exp1 = n > 0 and (n & (n - 1)) == 0
    exp2 = ( n & 0xAAAAAAAA) == 0
    return exp1 and exp2

# num = 16

num = 8
print(isPowerOfFour(num))
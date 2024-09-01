
# Problem link : https://leetcode.com/problems/power-of-two/

def isPowerOfTwo(n: int) -> bool:
    res = (n & (n - 1)) == 0
    return (n > 0) and res

# num = 15

# num = 1

num = 16
print(isPowerOfTwo(num))
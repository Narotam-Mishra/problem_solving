
## Problem link : https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/?envType=problem-list-v2&envId=bit-manipulation

def toHex(num: int) -> str:
    if num == 0:
        return "0"
    
    # handle negative numbers using two's complement
    if num < 0:
        num += 2 ** 32

    # convert number to hexadecimal
    return hex(num)[2:]

# num = 26

num = -1
print(toHex(num))
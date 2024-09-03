
## Problem link : https://leetcode.com/problems/find-the-difference/description/?envType=problem-list-v2&envId=bit-manipulation

def findTheDifference(s: str, t: str) -> str:
    res = 0

    # XOR all characters in both strings
    for char in s:
        res ^= ord(char)

    for char in t:
        res ^= ord(char)

    return chr(res)

s = "abcd"
t = "abcde"
print(findTheDifference(s, t))


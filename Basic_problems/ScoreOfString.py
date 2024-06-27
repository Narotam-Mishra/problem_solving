
## Problem link - https://leetcode.com/problems/score-of-a-string/?envType=daily-question&envId=2024-06-01

def scoreOfString(s: str) -> int:
    absDiff = 0
    for i in range(1, len(s)):
        absDiff += abs(ord(s[i-1]) - ord(s[i]))
    return absDiff

s = "hello"
score = scoreOfString(s)
print(score)

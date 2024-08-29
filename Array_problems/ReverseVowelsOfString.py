
## Problem link : https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75

def reverseVowels(s: str) -> str:
    vowels = "aeiouAEIOU"
    left = 0
    right = len(s) - 1

    # convert the string to a list of characters
    chars = list(s)

    while left < right:
        ## move left pointer until it finds a vowel
        while left < right and chars[left] not in vowels:
            left += 1

        ## move right pointer until it finds a vowel
        while left < right and chars[right] not in vowels:
            right -= 1
        
        ## swap vowels
        chars[left], chars[right] = chars[right], chars[left]
        left += 1
        right -= 1
    
    return ''.join(chars)

## example uage:
# s = "hello"

s = "leetcode"
print(reverseVowels(s))
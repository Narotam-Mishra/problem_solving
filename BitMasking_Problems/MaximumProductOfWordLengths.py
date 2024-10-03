
# Problem link - https://leetcode.com/problems/maximum-product-of-word-lengths/?envType=problem-list-v2&envId=bit-manipulation

from typing import List
def maxProduct(words: List[str]) -> int:
    n = len(words)
    bitmask = [0] * n
    max_prod = 0

    # Step 1: Convert each word to a bit mask
    for i in range(n):
        for ch in words[i]:
            # Set corresponding bit for each character
            bitmask[i] |= 1 << (ord(ch) - ord('a'))

    # Step 2: Compare each pair of words using their bit masks
    for i in range(n):
        for j in range(i + 1, n):
            # If AND of masks is 0, words have no common letters
            if bitmask[i] & bitmask[j] == 0:
                prod = len(words[i]) * len(words[j])
                max_prod = max(max_prod, prod)

    return max_prod

words = ["abcw","baz","foo","bar","xtfn","abcdef"]

# words = ["a","ab","abc","d","cd","bcd","abcd"]

# words = ["a","aa","aaa","aaaa"]
print(maxProduct(words))
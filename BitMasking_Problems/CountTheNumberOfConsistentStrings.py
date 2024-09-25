
# Problem link : https://leetcode.com/problems/count-the-number-of-consistent-strings/description/?envType=problem-list-v2&envId=bit-manipulation

from typing import List

def countConsistentStrings(allowed: str, words: List[str]) -> int:
    # convert 'allowed' string into a Set for efficient lookup of allowed characters
    allowed_set = set(allowed)

    consistent_count = 0

    # iterate over each word in the 'words' array
    for word in words:
        # check each character in the word
        if all(c in allowed_set for c in word):
            # if consistent, increment the counter
            consistent_count += 1

    # return the final count  
    return consistent_count

# allowed = "ab"
# words = ["ad","bd","aaab","baa","badab"]

allowed = "abc"
words = ["a","b","c","ab","ac","bc","abc"]
print(countConsistentStrings(allowed, words))
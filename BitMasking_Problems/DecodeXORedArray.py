
# Problem link : https://leetcode.com/problems/decode-xored-array/description/?envType=problem-list-v2&envId=bit-manipulation&favoriteSlug=&status=TO_DO&difficulty=EASY

# Key Concept : Inverse of XOR is XOR itself

from typing import List

def decode(encoded: List[int], first: int) -> List[int]:
    # initialize the original array with the first element.
    arr = [first]

    # reconstruct the rest of the array using the encoded values.
    for i in range(len(encoded)):
        arr.append(encoded[i] ^ arr[i])

    # return required array 'arr'
    return arr

# encoded = [1, 2, 3]
# first = 1

encoded = [6,2,7,3]
first = 4
print(decode(encoded, first))
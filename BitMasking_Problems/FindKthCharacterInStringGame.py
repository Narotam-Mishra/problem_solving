
# Problem link : https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/?envType=problem-list-v2&envId=bit-manipulation

def kthCharacter(k: int) -> str:
    # get number of set bits in the binary representation of (k - 1)
    flips = bin(k-1).count('1')

    # final character is determined by how many flips (bit counts) have occurred
    # we start with 'a' and move ahead in the alphabet by the number of flips
    return chr(ord('a') + flips)

# k = 5

# k = 100

k = 500
print(kthCharacter(k))
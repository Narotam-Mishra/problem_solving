
# Problem link : https://leetcode.com/problems/complement-of-base-10-integer/?envType=problem-list-v2&envId=bit-manipulation

def bitwiseComplement(n: int) -> int:
    ## edge case:
    if n == 0:
        return 1
    
    ## step 1: find the bit length of the number
    bit_length = n.bit_length()

    ## step 2: create a mask of the same length with all bits set to 1
    bit_mask = (1 << bit_length) - 1

    ## step 3: XOR the number with the mask to get the complement
    return n ^ bit_mask

# num = 5

# num = 10

num = 7
print(bitwiseComplement(num))
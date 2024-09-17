
# Problem link : https://leetcode.com/problems/xor-operation-in-an-array/?envType=problem-list-v2&envId=bit-manipulation

def xorOperation(n: int, start: int) -> int:
    xorVal = 0

    for i in range(n):
        # calculate running XOR value
        xorVal ^= start + 2 * i

    # return XOR value 'xorVal'
    return xorVal

n = 5
start = 0
print(xorOperation(n, start))
    
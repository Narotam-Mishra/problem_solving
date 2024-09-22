
# Problem link - https://leetcode.com/problems/sum-of-two-integers/description/?envType=problem-list-v2&envId=bit-manipulation

def getSum(a: int, b: int) -> int:
        # 32 bit mask in hexadecimal
        mask = 0xffffffff

        while (b & mask) != 0:
            # calculate carry
            carry = (a & b) << 1

            # calculate sum without carry
            a = a ^ b

            # assign carry to b
            b = carry
    
        return (a & mask) if b > 0 else a

a = 2
b = 3
print(getSum(a, b))
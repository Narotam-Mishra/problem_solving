
# Problem link - https://leetcode.com/problems/add-digits/description/?envType=problem-list-v2&envId=number-theory

def find_digits_sum(num: int) -> int:
    s = 0
    while(num > 0):
        s += num % 10
        num //= 10
    return s

def addDigits(num: int) -> int:
    while num >= 10:
        num = find_digits_sum(num)
    return num

# num = 199

num = 38
print(addDigits(num))
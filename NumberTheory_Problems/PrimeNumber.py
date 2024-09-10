
## Problem link : https://www.geeksforgeeks.org/problems/prime-number2314/1

import math

def isPrime (n):
    # corner case:
    if n <= 1:
        return 0
    
    # check from 2 to sqrt(n)
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return 0
        
    # if no divisors are found, n is prime
    return 1

# num = 11

num = 21
print(isPrime(num))
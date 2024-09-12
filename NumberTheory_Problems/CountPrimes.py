
# Problem link - https://leetcode.com/problems/count-primes/description/

def prime_sieve(maxN):
    # corner case
    if(maxN < 2):
        return []
    
    primes = [False] * (maxN + 1)

    # first mark all odd numbers as prime
    for i in range(3, maxN + 1, 2):
        primes[i] = True

    # prime sieve logic
    for i in range(3, int(maxN**0.5) + 1, 2):
        # if the current number is not marked then it is prime
        if primes[i] == True:
            # mark all the multiples of i as not prime
            for j in range(i * i, maxN + 1, i):
                primes[j] = False

    # special corner cases:
    primes[2] = True
    primes[0] = primes[1] = False

    return primes

def count_primes(n):
    count = 0
    primes = prime_sieve(n)

    for i in range(1, n):
        if primes[i]:
            count += 1

    return count

num = 10
print(count_primes(num)) 

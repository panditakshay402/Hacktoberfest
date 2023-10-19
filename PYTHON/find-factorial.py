# Function to find prime factors of a number
def primeFactors(n):
    factors = {}
    i = 2
    while i*i <= n:
        while n % i == 0:
            if i not in factors:
                factors[i] = 0
            factors[i] += 1
            n //= i
        i += 1
    if n > 1:
        if n not in factors:
            factors[n] = 0
        factors[n] += 1
    return factors
 
# Function to find factorial of a number
def factorial(n):
    result = 1
    for i in range(2, n+1):
        factors = primeFactors(i)
        for p in factors:
            result *= p ** factors[p]
    return result
 
# Driver Code
num = 7
print("Factorial of", num, "is", factorial(num))

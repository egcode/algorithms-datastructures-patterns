def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors


if __name__ == "__main__":
    '''
        15 = 3 * 5
        8 = 2 * 2 * 2
        6 = 2 * 3
    '''
    print(prime_factors(15)) # [3, 5]
    print(prime_factors(8)) # [2, 2, 2]
    print(prime_factors(6)) # [2, 3]        
#!/usr/bin/python3
from sympy import isprime, factorint


def factorize_rsa_number(n):
    # Check if the number is prime
    if isprime(n):
        return f"{n} is a prime number, so p={n} and q=1"

    # Factorize the number into its prime components
    factors = factorint(n)

    # Extract prime factors
    prime_factors = [factor for factor,
                    exponent in factors.items() if exponent > 0]

    if len(prime_factors) == 2:
        return f"{n} = p * q, where p={prime_factors[0]}
                and q={prime_factors[1]}"
    else:
        return f"Unable to factorize {n} into two prime numbers."


if __name__ == "__main__":
    # Replace this number with your RSA number
    rsa_number = 1234567890123456789012345678901234567890

    result = factorize_rsa_number(rsa_number)
    print(result)

#!/usr/bin/python3
import sys


def factorize(number):
    # Start with the smallest possible factor
    factor = 2
    while factor * factor <= number:
        if number % factor == 0:
            # Found a factor, print the factorization
            other_factor = number // factor
            print(f"{number}={factor}*{other_factor}")
            return
        factor += 1

    # If the number is a prime, print it as a factorization of itself
    print(f"{number}={number}*1")


def main(filename):
    with open(filename, 'r') as file:
        for line in file:
            # Convert each line to an integer and factorize
            number = int(line.strip())
            factorize(number)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)

    filename = sys.argv[1]
    main(filename)

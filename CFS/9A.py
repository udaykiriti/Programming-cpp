

"""
    Codeforces Problem 9A - Die Roll

    Yakko and Wakko roll a standard 6-sided die and get values Y and W.
    Dot wants to know the probability that she can win by rolling a value
    that is at least as high as the maximum of Y and W. If she ties, she wins.

    The total number of outcomes on a 6-sided die is 6.
    The number of favorable outcomes is (6 - max(Y, W) + 1).
    The output is the simplified probability of winning as a fraction.
"""

from fractions import Fraction

def main():
    a, b = map(int, input().split())
    max_val = max(a, b)
    favorable = 6 - max_val + 1
    total = 6
    result = Fraction(favorable, total)
    print(f"{result.numerator}/{result.denominator}")

main()

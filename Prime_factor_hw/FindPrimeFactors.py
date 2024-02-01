# File: FindPrimeFactors.py
# Student: Alana Gaughan
# UT EID: arg5345
# Course Name: CS303E
#
# Date: 3/16/23
# Description of Program: This program finds the prime factors of a given number

import math


def findNextPrime(num):
    """ Find the first prime > num. """
    if num < 2:
        return 2
    # If (num >= 2 and num is even ), the next prime after num is at least (num - 1) + 2 , which is odd.
    if num % 2 == 0:
        num -= 1
    guess = num + 2
    while not isPrime(guess):
        guess += 2
    return guess


def isPrime ( num ):
    """ Test whether num is prime . """
    # Deal with evens and numbers < 2.
    if ( num < 2 or num % 2 == 0 ):
        return ( num == 2 )
    # See if there are any odd divisors
    # up to the square root of num.
    divisor = 3
    while ( divisor <= math.sqrt ( num )):
        if ( num % divisor == 0 ):
            return False
        else:
            divisor += 2
    return True


print("Find Prime Factors:")
user_number = 1
while user_number != 0:
    user_number = int(input("Enter a positive integer (or 0 to stop): "))
    if user_number == 0:
        break
    factorization = []
    if user_number == 1:
        print("\t1 has no prime factorization.\n")
    elif user_number < 0:
        print("\tNegative integer entered. Try again.\n")
    else:
        if isPrime(user_number):
            factorization.append(user_number)
        else:
            d = 2
            num = user_number
            while num > 1:
                if num % d == 0:
                    factorization.append(d)
                    num /= d
                else:
                    d = findNextPrime(d)
        print(f"\tThe prime factorization of {user_number} is: {factorization}\n")

print("Goodbye!")


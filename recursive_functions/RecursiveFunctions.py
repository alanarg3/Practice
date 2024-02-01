# File: RecursiveFunctions.py
# Student: Alana Gaughan
# UT EID: arg5345
# Course Name: CS303E
#
# Date: 4/7/23
# Description of Program: Performs multiple recursive functions


def sumItemsInList( L ):
    """ Given a list of numbers, return the sum. """
    if L == []:
        return 0
    else:
        return L[0] + sumItemsInList( L[1:] )


def countOccurrencesInList( key, L ):
    """ Return the number of times key occurs in list L. """
    if not L:                 # same as L == []:
        return 0
    elif key == L[0]:
        return 1 + countOccurrencesInList(key, L[1:])
    else:
        return countOccurrencesInList(key, L[1:])


def addToN (n):
    """ Return the sum of the non-negative integers to n. E.g., addToN( 5 ) = 0 + 1 + 2 + 3 + 4 + 5. """
    if n == 0:
        return n
    return n + addToN(n-1)

def findSumOfDigits( n ):
    """ Return the sum of the digits in a non-negative integer. """
    if n % 10 == n:   # check this line
        return n
    m = n % 10
    return m + findSumOfDigits((n - m) // 10)

def integerToBinary( n ):
    """ Given a nonnegative integer n, return the binary representation as a string. """
    # 0 = 0 == 0
    # 1 = 1 == 2^0
    # 2 = 10 == 2^1
    # 3 = 11 == 2^1 + 2^0
    # 4 = 100 == 2^2 + 0 + == 4
    # 5 = 101 == 2^2 + 0 + 2^0 == 4 + 1
    # 6 = 110 == 2^2 + 2^1 + 0 == 4 + 2
    # 7 = 111 == 2^2 + 2^1 + 2^0, == 4 + 2 + 1
    # 8 = 1000 == 8 + 0
    # 9 = 1001 == 8 + 1
    if n == 0:
        return '0'
    if n == 1:
        return '1'
    if n % 2 == 0:
        digit = '0'
    if n % 2 == 1:
        digit = '1'
    return integerToBinary(n//2) + digit


def integerToList( n ):
    """ Given a non-negative integer, return a list of the digits (as strings). """
    if n % 10 == n:
        return [str(n)]
    m = n % 10
    return integerToList(n // 10) + [str(m)]


def isPalindrome( s ):
    """ Return True if string s is a palindrome and False otherwise. Count the empty string as a palindrome. """
    if s == "":
        return True
    if s[0] == s[-1]:
        return isPalindrome(s[1:-1])
    else:
        return False



def findFirstUppercase( s ):
    """ Return the first uppercase letter in string s, if any. Return None if there is none. """
    if not s:
        return
    if 64 < ord(s[0]) < 91:
        return s[0]
    return findFirstUppercase(s[1:])

# for this one, don't reverse the string.


def findLastUppercase( s ):
    """ Return the last uppercase letter in string s, if any. Return None if there is none. """
    if not s:
        return
    if 64 < ord(s[-1]) < 91: #test with capital z at the end of the word
        return s[-1]
    return findLastUppercase(s[:-1])


def findFirstUppercaseIndexHelper( s, index ):
    """ Helper function for findFirstUppercaseIndex. Return the index of the first uppercase letter;
    assume you are starting at index. Return -1 if there is none."""
    if not s:
        return -1
    if 64 < ord(s[0]) < 91:
        return index
    return findFirstUppercaseIndexHelper(s[1:], index + 1)


# The following function is already completed for you. But
# make sure you understand what it's doing.

def findFirstUppercaseIndex( s ):
    """ Return the index of the first uppercase letter in string s, if any. Return -1 if there is none.
    This one requires a helper function, which is the recursive function. """
    return findFirstUppercaseIndexHelper( s, 0 )

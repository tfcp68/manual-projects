import itertools
from math import factorial
from itertools import product
from itertools import permutations
from itertools import combinations_with_replacement

def permutation(number):
    return factorial(number)


def permutation_repeat(number, *args):
    divider = 1
    for k in args:
        if k <= number:
            divider *= factorial(k)
        else:
            return "ERROR"
    return int(factorial(number) / divider)


def permute_with_repeat(items, length):
    permutations = []

    def generate(prefix):
        if len(prefix) == length:
            permutations.append(prefix)
        else:
            for item in items:
                generate(prefix + (item,))

    generate(())
    return permutations


def permute_by_index(items, length, index):
    total_permutations = len(items) ** length
    if index >= total_permutations:
        return "Index out of range"
    else:
        permutation = permute_with_repeat(items, length)
        return permutation[index]


def index_by_permutation(items, length, substring):
    permutation = permute_with_repeat(items, length)
    if len(substring) == length:
        return permutation.index(substring)
    else:
        return "Substring is not equal to the string"



items = ['pig', 'dog', 'cat']
length = 3
index = 16
substring = ('dog', 'cat', 'dog')


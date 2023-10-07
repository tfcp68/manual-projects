import itertools

import pytest
from math import factorial
from itertools import permutations
from permutations import *

def my_sum(a, b):
    return a + b


class Test:
    items = ['pig', 'dog', 'cat']
    length = 3
    index = 16
    substring = ('dog', 'cat', 'dog')

    def test_my_sum(self):
        assert my_sum(3, 3) == 6


    def test_permutation(self):
        assert permutation(5) == 120
        assert permutation(0) == 1
        assert permutation(1) == 1
        assert permutation(2) == 2
        assert permutation(3) == 6
        assert permutation(4) == 24


    def test_permutation1(self):
        assert permutation(4) == 24


    def test_permutation2(self):
        assert permutation(9) == 362880

    def test_permut_repeat(self):
        assert permutation_repeat(11, 3, 3, 2) == 554400

    def test_permut_repeat(self):
        assert permutation_repeat(10, 2, 3, 2, 1, 1, 1) == 151200

    def test_permute_with_repeat(self):
        assert permute_with_repeat(items, length) == [('pig', 'pig', 'pig'), ('pig', 'pig', 'dog'), ('pig', 'pig', 'cat'), ('pig', 'dog', 'pig'), ('pig', 'dog', 'dog'), ('pig', 'dog', 'cat'), ('pig', 'cat', 'pig'), ('pig', 'cat', 'dog'), ('pig', 'cat', 'cat'), ('dog', 'pig', 'pig'), ('dog', 'pig', 'dog'), ('dog', 'pig', 'cat'), ('dog', 'dog', 'pig'), ('dog', 'dog', 'dog'), ('dog', 'dog', 'cat'), ('dog', 'cat', 'pig'), ('dog', 'cat', 'dog'), ('dog', 'cat', 'cat'), ('cat', 'pig', 'pig'), ('cat', 'pig', 'dog'), ('cat', 'pig', 'cat'), ('cat', 'dog', 'pig'), ('cat', 'dog', 'dog'), ('cat', 'dog', 'cat'), ('cat', 'cat', 'pig'), ('cat', 'cat', 'dog'), ('cat', 'cat', 'cat')]

    def test_permute_with_repeat(self):
        assert permute_with_repeat(items, length) == itertools.permutations(items, length)

import unittest
from math import perm
from itertools import permutations
from random import randint
from perm import *


class TestPermutations(unittest.TestCase):
    def test_GetPermutationsAmount(self):
        self.assertEqual(GetPermutationsAmount(1), 1)
        self.assertEqual(GetPermutationsAmount(2), 2)
        self.assertEqual(GetPermutationsAmount(3), 6)
        self.assertEqual(GetPermutationsAmount(4), 24)
        self.assertEqual(GetPermutationsAmount(5), 120)
        self.assertEqual(GetPermutationsAmount(6), 720)
        self.assertEqual(GetPermutationsAmount(7), 5040)

        for _ in range(1000):
            k = randint(1, 1000)
            permutation = perm(k)

            self.assertEqual(GetPermutationsAmount(k), permutation)

    def test_GetNextPermutationInLexicographicOrder(self):
        self.assertEqual(GetNextPermutationInLexicographicOrder([1]), [])
        self.assertEqual(GetNextPermutationInLexicographicOrder([1, 2]), [2, 1])
        self.assertEqual(GetNextPermutationInLexicographicOrder([1, 2, 3]), [1, 3, 2])
        self.assertEqual(GetNextPermutationInLexicographicOrder([1, 3, 2]), [2, 1, 3])
        self.assertEqual(GetNextPermutationInLexicographicOrder([2, 1, 3]), [2, 3, 1])
        self.assertEqual(GetNextPermutationInLexicographicOrder([2, 3, 1]), [3, 1, 2])
        self.assertEqual(GetNextPermutationInLexicographicOrder([3, 1, 2]), [3, 2, 1])
        self.assertEqual(GetNextPermutationInLexicographicOrder([4, 3, 1, 2]), [4, 3, 2, 1])
        self.assertEqual(GetNextPermutationInLexicographicOrder([3, 5, 8, 2, 4, 1, 7, 6]), [3, 5, 8, 2, 4, 6, 1, 7])

        for _ in range(50):
            t = randint(2, 10)
            k = randint(1, GetPermutationsAmount(t) - 1)
            p = [i + 1 for i in range(t)]
            z = list(permutations(p, t))
            self.assertEqual(GetNextPermutationInLexicographicOrder(list(z[k - 1])), list(z[k]))

    def test_GenerateAllPermutationsInLexicographicOrder(self):
        self.assertEqual(GenerateAllPermutationsInLexicographicOrder(1), [[1]])
        self.assertEqual(GenerateAllPermutationsInLexicographicOrder(2), [[1, 2], [2, 1]])
        self.assertEqual(GenerateAllPermutationsInLexicographicOrder(3),
                         [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]])
        self.assertEqual(GenerateAllPermutationsInLexicographicOrder(4),
                         [[1, 2, 3, 4], [1, 2, 4, 3], [1, 3, 2, 4], [1, 3, 4, 2], [1, 4, 2, 3], [1, 4, 3, 2],
                          [2, 1, 3, 4], [2, 1, 4, 3], [2, 3, 1, 4], [2, 3, 4, 1], [2, 4, 1, 3], [2, 4, 3, 1],
                          [3, 1, 2, 4], [3, 1, 4, 2], [3, 2, 1, 4], [3, 2, 4, 1], [3, 4, 1, 2], [3, 4, 2, 1],
                          [4, 1, 2, 3], [4, 1, 3, 2], [4, 2, 1, 3], [4, 2, 3, 1], [4, 3, 1, 2], [4, 3, 2, 1]])

    def test_GetPermutationByPosition(self):
        self.assertEqual(GetPermutationByPosition(1, 3), 123)
        self.assertEqual(GetPermutationByPosition(2, 3), 132)
        self.assertEqual(GetPermutationByPosition(3, 3), 213)
        self.assertEqual(GetPermutationByPosition(4, 3), 231)
        self.assertEqual(GetPermutationByPosition(5, 3), 312)
        self.assertEqual(GetPermutationByPosition(6, 3), 321)
        self.assertEqual(GetPermutationByPosition(7, 3), -1)
        self.assertEqual(GetPermutationByPosition(1, 1), 1)
        self.assertEqual(GetPermutationByPosition(1, 5), 12345)
        self.assertEqual(GetPermutationByPosition(120, 5), 54321)

        for _ in range(10):
            t = randint(1, 10)
            k = randint(1, GetPermutationsAmount(t))
            p = [i + 1 for i in range(t)]
            z = list(permutations(p, t))[k - 1]
            d = ''
            for i in z:
                d += str(i)
            self.assertEqual(GetPermutationByPosition(k, t), int(d))

    def test_GetPositionByPermutation(self):
        self.assertEqual(GetPositionByPermutation(3, [1, 2, 3]), 1)
        self.assertEqual(GetPositionByPermutation(3, [1, 3, 2]), 2)
        self.assertEqual(GetPositionByPermutation(3, [2, 1, 3]), 3)
        self.assertEqual(GetPositionByPermutation(3, [2, 3, 1]), 4)
        self.assertEqual(GetPositionByPermutation(3, [3, 1, 2]), 5)
        self.assertEqual(GetPositionByPermutation(3, [3, 2, 1]), 6)
        self.assertEqual(GetPositionByPermutation(1, [1]), 1)
        self.assertEqual(GetPositionByPermutation(4, [4, 3, 2, 1]), 24)
        self.assertEqual(GetPositionByPermutation(3, [2, 1]), -1)
        self.assertEqual(GetPositionByPermutation(3, [4, 2, 1]), -1)
        self.assertEqual(GetPositionByPermutation(3, [3, 3, 3]), -1)

        for _ in range(10):
            t = randint(1, 10)
            k = randint(1, GetPermutationsAmount(t))
            p = [i + 1 for i in range(t)]
            z = list(permutations(p, t))[k - 1]
            self.assertEqual(GetPositionByPermutation(t, z), k)


if __name__ == "__main__":
    unittest.main()

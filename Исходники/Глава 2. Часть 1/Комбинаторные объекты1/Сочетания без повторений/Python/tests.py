import unittest
from math import perm
from itertools import permutations
from random import randint
from Placements import *


class TestReplacements(unittest.TestCase):
    def test_GetReplacementsCount(self):

        # By hands
        self.assertEqual(GetPlacementsCount(5, 3), 60)
        self.assertEqual(GetPlacementsCount(10, 2), 90)
        self.assertEqual(GetPlacementsCount(12, 2), 132)
        self.assertEqual(GetPlacementsCount(12, 10), 239500800)
        self.assertEqual(GetPlacementsCount(12, 5), 95040)
        self.assertEqual(GetPlacementsCount(12, 1), 12)
        self.assertEqual(GetPlacementsCount(5, 4), 120)
        self.assertEqual(GetPlacementsCount(25, 4), 303600)
        self.assertEqual(GetPlacementsCount(25, 20), 129260083694424883200000)
        self.assertEqual(GetPlacementsCount(90, 2), 8010)
        self.assertEqual(GetPlacementsCount(3, 3), 6)
        self.assertEqual(GetPlacementsCount(2, 2), 2)
        self.assertEqual(GetPlacementsCount(10, 10), 3628800)
        self.assertEqual(GetPlacementsCount(50, 50), 30414093201713378043612608166064768844377641568960512000000000000)
        self.assertEqual(GetPlacementsCount(25, 10), 11861676288000)
        self.assertEqual(GetPlacementsCount(77, 5), 2370937800)
        self.assertEqual(GetPlacementsCount(22, 5), 3160080)
        self.assertEqual(GetPlacementsCount(22, 21), 1124000727777607680000)
        self.assertEqual(GetPlacementsCount(50, 20), 114660755112113373922453094400000)
        self.assertEqual(GetPlacementsCount(1, 1), 1)
        self.assertEqual(GetPlacementsCount(64, 63),
                         126886932185884164103433389335161480802865516174545192198801894375214704230400000000000000)
        self.assertEqual(GetPlacementsCount(64, 2), 4032)
        self.assertEqual(GetPlacementsCount(100, 10), 62815650955529472000)
        self.assertEqual(GetPlacementsCount(200, 10), 81470204436547390464000)
        self.assertEqual(GetPlacementsCount(333, 8), 138918263285708565120)
        self.assertEqual(GetPlacementsCount(667, 14), 3006811939555475472917993200067460096000)
        self.assertEqual(GetPlacementsCount(55, 5), 417451320)
        self.assertEqual(GetPlacementsCount(55, 15), 15560933364451705950720000)
        self.assertEqual(GetPlacementsCount(2, 1), 2)
        self.assertEqual(GetPlacementsCount(1000, 2), 999000)
        self.assertEqual(GetPlacementsCount(1000, 10), 955860613004397508326213120000)
        self.assertEqual(GetPlacementsCount(568, 17), 52349667397461300920137494190678244718379008000)
        self.assertEqual(GetPlacementsCount(99, 55),
                         351078559200149679413117488175363602453135331275499185304858030453069232236379811746938880000000000000)
        self.assertEqual(GetPlacementsCount(77, 33), 54615598122189553451044301556840634955720992751616000000000)
        self.assertEqual(GetPlacementsCount(10, 5), 30240)
        self.assertEqual(GetPlacementsCount(23, 6), 72681840)
        self.assertEqual(GetPlacementsCount(73, 7), 8211917004480)
        self.assertEqual(GetPlacementsCount(23, 20), 4308669456480829440000)
        self.assertEqual(GetPlacementsCount(800, 100),
                         318348570470064569508445601406351602968190694577069589038281824603661835016749890067789545136693057055243946216369553952355779066749887611604731730933616265990373085551988457684259383883447348281438473248513898254949269233329603054232671837416727434131293014589440000000000000000000000000)
        self.assertEqual(GetPlacementsCount(150, 40),
                         3597292614445561520158671789370178969359700771419675347809280434032449945600000000000)
        self.assertEqual(GetPlacementsCount(44, 43), 2658271574788448768043625811014615890319638528000000000)
        self.assertEqual(GetPlacementsCount(55, 55),
                         12696403353658275925965100847566516959580321051449436762275840000000000000)

        # Random
        for testsAmount in range(1000):
            n = randint(1, 1000)
            m = randint(1, n)

            Placements = perm(n, m)

            self.assertEqual(GetPlacementsCount(n, m), Placements)

    def test_GetPlacementsInLexicographicOrder(self):

        # Random
        for testsAmount in range(1000):
            n = randint(2, 10)
            m = randint(1, n - 1)
            a = [x for x in range(1, n + 1)]
            placements = (list(permutations(a, m)))

            self.assertEqual(GetPlacementsInLexicographicOrder(n, m), placements)

    def test_GetNextPlacementInLexicographicOrder(self):

        # By hands
        self.assertEqual(GetNextPlacementInLexicographicOrder(3, 3, [1, 2, 3]), [1, 3, 2])
        self.assertEqual(GetNextPlacementInLexicographicOrder(3, 2, [2, 1]), [2, 3])
        self.assertEqual(GetNextPlacementInLexicographicOrder(3, 2, [2, 1]), [2, 3])
        self.assertEqual(GetNextPlacementInLexicographicOrder(4, 2, [4, 1]), [4, 2])
        self.assertEqual(GetNextPlacementInLexicographicOrder(4, 2, [4, 2]), [4, 3])
        self.assertEqual(GetNextPlacementInLexicographicOrder(4, 2, [3, 1]), [3, 2])
        self.assertEqual(GetNextPlacementInLexicographicOrder(4, 2, [3, 2]), [3, 4])
        self.assertEqual(GetNextPlacementInLexicographicOrder(10, 3, [3, 2, 1]), [3, 2, 4])
        self.assertEqual(GetNextPlacementInLexicographicOrder(10, 3, [5, 2, 1]), [5, 2, 3])
        self.assertEqual(GetNextPlacementInLexicographicOrder(10, 3, [5, 4, 1]), [5, 4, 2])
        self.assertEqual(GetNextPlacementInLexicographicOrder(10, 3, [5, 3, 7]), [5, 3, 8])
        self.assertEqual(GetNextPlacementInLexicographicOrder(10, 3, [5, 3, 8]), [5, 3, 9])
        self.assertEqual(GetNextPlacementInLexicographicOrder(10, 5, [5, 3, 8, 1, 2]), [5, 3, 8, 1, 4])
        self.assertEqual(GetNextPlacementInLexicographicOrder(10, 5, [5, 3, 8, 1, 6]), [5, 3, 8, 1, 7])
        self.assertEqual(GetNextPlacementInLexicographicOrder(10, 6, [5, 3, 8, 4, 7, 1]), [5, 3, 8, 4, 7, 2])
        self.assertEqual(GetNextPlacementInLexicographicOrder(3, 2, [1, 2]), [1, 3])
        self.assertEqual(GetNextPlacementInLexicographicOrder(4, 2, [3, 2]), [3, 4])
        self.assertEqual(GetNextPlacementInLexicographicOrder(4, 2, [3, 2]), [3, 4])
        self.assertEqual(GetNextPlacementInLexicographicOrder(5, 2, [4, 3]), [4, 5])
        self.assertEqual(GetNextPlacementInLexicographicOrder(12, 10, [4, 3, 2, 1, 5, 6, 7, 8, 9, 10]),
                         [4, 3, 2, 1, 5, 6, 7, 8, 9, 11])
        self.assertEqual(GetNextPlacementInLexicographicOrder(12, 10, [4, 3, 2, 1, 5, 6, 7, 8, 9, 11]),
                         [4, 3, 2, 1, 5, 6, 7, 8, 9, 12])
        self.assertEqual(GetNextPlacementInLexicographicOrder(11, 10, [4, 3, 2, 1, 5, 6, 7, 8, 9, 10]),
                         [4, 3, 2, 1, 5, 6, 7, 8, 9, 11])
        self.assertEqual(GetNextPlacementInLexicographicOrder(11, 10, [4, 3, 2, 1, 5, 6, 7, 8, 9, 10]),
                         [4, 3, 2, 1, 5, 6, 7, 8, 9, 11])

        # Random
        for testAmount in range(1000):
            n = randint(2, 10)
            m = randint(1, n - 1)
            a = [x for x in range(1, n + 1)]
            answer = PlacementGenerator(n, m)
            placements = (list(permutations(a, m)))
            if (placements.index(answer) + 1) < m:
                result = placements[placements.index(answer) + 1]

                self.assertEqual(GetNextPlacementInLexicographicOrder(n, m, list(answer)), list(result))

    def test_GetPlacementByIndex(self):
        for testAmount in range(100):
            n = randint(2, 10)
            m = randint(1, n - 1)
            index = randint(1, m)
            a = [x for x in range(1, n + 1)]
            placements = (list(permutations(a, m)))
            result = placements[index]

            self.assertEqual(GetPlacementByIndex(n, m, index), result)

    def test_GetIndexByPlacement(self):
        for testAmount in range(1000):
            n = randint(2, 10)
            m = randint(1, n - 1)
            a = [x for x in range(1, n + 1)]
            placement = PlacementGenerator(n, m)
            placements = (list(permutations(a, m)))
            if (placements.index(placement) + 1) < m:
                result = placements.index(placement)

                self.assertEqual(GetIndexByPlacement(n, m, list(placement)), result)


def PlacementGenerator(n, m):
    result = []

    for generation in range(m):
        num = randint(1, n)

        while num in result:
            num = randint(1, n)

        result.append(num)

    return tuple(result)


if __name__ == "__main__":
    unittest.main()
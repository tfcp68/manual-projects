import Repetition_placement
import pytest
import random


def test_placement1():
    assert Repetition_placement.RepetitionPlacement(-1, 54) == 1

def test_placement_random():
    boolin = True
    for i in range(20):
        a = random.randint(1, 30)
        k = Repetition_placement.RepetitionPlacement(a, 10)
        if 10**a != k:
            boolin = False
    assert boolin == True


def test_placement_generation_random():
    boolin = True
    for i in range(20):
        a = random.randint(1, 5)
        f = random.randint(1, 11)
        k = Repetition_placement.RepetitionPlacement_generation(a, f)
        if f**a != len(k):
            boolin = False
    assert boolin == True

def test_placement_number1():
    a = 100
    assert Repetition_placement.RepetitionPlacement_number(2, 20, a) == [5, 0]

def test_placement_number2():
    a = 100
    assert Repetition_placement.RepetitionPlacement_number(2, 50, a) == [2, 0]

def test_placement_number3():
    a = 100
    assert Repetition_placement.RepetitionPlacement_number(5, 5, a) == [0, 0, 4, 0, 0]

def test_placement_number_random():
    boolin = True
    for i in range(20):
        a = random.randint(1, 5)
        a1 = random.randint(0, 10**a-1)
        k = Repetition_placement.RepetitionPlacement_generation(a, 10)
        k1 = Repetition_placement.RepetitionPlacement_number(a, 10, a1)
        if k[a1] != k1:
            boolin = False
    assert boolin == True

def test_placement_plac_random1():
    boolin = True
    for i in range(20):
        a = random.randint(1, 5)
        a1 = random.randint(0, 10**a-1)
        a2 = random.randint(0, 10**a-1)
        k = Repetition_placement.RepetitionPlacement_generation(a, 10)
        k1 = Repetition_placement.RepetitionPlacement_number(a, 10, a1)
        k2 = Repetition_placement.RepetitionPlacement_plac(a, 10, k1)
        if k.index(k1) != k2:
            boolin = False
    assert boolin == True

def test_placement_plac_random2():
    boolin = True
    for i in range(10):
        a = random.randint(1, 5)
        f = random.randint(1, 20)
        a1 = random.randint(0, f**a-1)
        a2 = random.randint(0, f**a-1)
        k = Repetition_placement.RepetitionPlacement_generation(a, f)
        k1 = Repetition_placement.RepetitionPlacement_number(a, f, a1)
        k2 = Repetition_placement.RepetitionPlacement_plac(a, f, k1)
        if k.index(k1) != k2:
            boolin = False
    assert boolin == True


def test_plac_plus_1_rand():
    boolin = True
    for i in range(10):
        a = random.randint(1, 5)
        f = random.randint(1, 20)
        a1 = random.randint(0, f ** a - 1)
        a2 = random.randint(0, f ** a - 1)
        k = Repetition_placement.RepetitionPlacement_generation(a, f)
        k1 = Repetition_placement.RepetitionPlacement_number(a, f, a1)
        n1 = Repetition_placement.RepetitionPlacement_plac(a, f, k1)
        k3 = Repetition_placement.RepetitionPlacement_plac_plus_1(a, f, k1)
        n2 = Repetition_placement.RepetitionPlacement_plac(a, f, k3)
        if n2-n1 != 1:
            boolin = False
    assert boolin == True
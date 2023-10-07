
def quick_sort(array: list):
    if len(array) < 2:
        return array
    pivot_index = len(array) // 2
    pivot = array[pivot_index]
    array.pop(pivot_index)
    big, small = list(), list()
    for i in array:
        if i > pivot:
            big.append(i)
        else:
            small.append(i)
    return quick_sort(small) + [pivot] + quick_sort(big)


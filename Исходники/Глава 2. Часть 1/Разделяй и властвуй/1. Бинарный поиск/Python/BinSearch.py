
def bin_search(array, data):
    begin = 0
    end = len(array) - 1
    while begin <= end:
        middle = (begin + end) // 2
        guess = array[middle]
        if guess == data:
            return middle
        if guess < data:
            begin = middle + 1
        else:
            end = middle - 1
    return -1





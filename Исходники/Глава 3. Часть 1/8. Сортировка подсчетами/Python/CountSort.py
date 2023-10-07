

def counting_sort(array):
    count = [0] * (max(array) + 1)
    result = [0] * len(array)

    for i in array:
        count[i] += 1

    for j in range(1, len(count)):
        count[j] += count[j - 1]

    for i in reversed(array):
        count[i] -= 1
        result[count[i]] = i

    return result






def counting_sort_negative(array):
    low = min(array)
    high = max(array)

    count = [0 for _ in range(low, high + 1)]
    result = [0] * len(array)
    for i in array:
        count[i - low] += 1

    for j in range(1, len(count)):
        count[j] += count[j - 1]

    for i in reversed(array):
        count[i - low] -= 1
        result[count[i - low]] = i

    return result


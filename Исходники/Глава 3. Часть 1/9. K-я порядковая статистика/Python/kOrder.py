

def k_order_statistic(arr, k):

    if len(arr) == 1:
        return arr[0]

    pivot = arr[len(arr) // 2]

    left = [x for x in arr if x < pivot]

    right = [x for x in arr if x > pivot]

    equal = [x for x in arr if x == pivot]

    if k < len(left):
        return k_order_statistic(left, k)

    elif k < len(left) + len(equal):
        return equal[0]

    else:
        return k_order_statistic(right, k - len(left) - len(equal))





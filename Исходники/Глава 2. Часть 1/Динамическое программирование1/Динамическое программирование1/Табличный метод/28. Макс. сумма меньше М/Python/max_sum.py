def max_sum_enumeration(arr: list, m: int):
    n = len(arr)
    need_sum = -1
    for i in range(0, n):
        for j in range(0, i + 1):
            temp_sum = 0
            for k in range(j, i + 1):
                temp_sum += arr[k]
            if need_sum < temp_sum <= m:
                need_sum = temp_sum
    return need_sum


def max_sum_dp(arr: list, m: int):
    n = len(arr)
    need_sum = -1
    prefix_arr = [0] * len(arr)
    prefix_arr[0] = arr[0]
    for k in range(1, len(arr)):
        prefix_arr[k] = prefix_arr[k - 1] + arr[k]
    for i in range(0, n):
        for j in range(0, i + 1):
            temp_sum = prefix_arr[i] - prefix_arr[j] + arr[j]
            if need_sum < temp_sum <= m:
                need_sum = temp_sum
    return need_sum


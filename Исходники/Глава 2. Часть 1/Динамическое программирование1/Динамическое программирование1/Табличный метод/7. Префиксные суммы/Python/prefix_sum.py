def prefix_sum(arr):
    prefix_arr = [0] * len(arr)
    prefix_arr[0] = arr[0]
    for k in range(1, len(arr)):
        prefix_arr[k] = prefix_arr[k - 1] + arr[k]
    return prefix_arr

#
# a = [-9, 2, 3, 6, -5, 1, -1, 7, 8]
# print(prefix_sum(a))
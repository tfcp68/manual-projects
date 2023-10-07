
def array_in_half(array):
    if len(array) > 1:
        middle = len(array) // 2
        return [array[:middle], array[middle:]]
    return array


def split_array(array):
    if len(array) == 1:
        return [array]
    first, second = array_in_half(array)
    return split_array(first) + split_array(second)


def sort_merge(arrays):
    first, second = arrays
    i = j = cnt_inv = 0
    new_array = []
    while i < len(first) and j < len(second):
        if first[i] < second[j]:
            new_array.append(first[i])
            i += 1
        else:
            new_array.append(second[j])
            cnt_inv += (len(first) - i)
            j += 1
    if i < len(first) or j < len(second):
        new_array += first[i:len(first)]
        new_array += second[j:len(second)]
    return new_array, cnt_inv


def merge(array, cnt=0):
    final_array = []
    if len(array) % 2 > 0:
        array.append([])
    for i in range(0, len(array)-1, 2):
        curr, c = sort_merge([array[i], array[i + 1]])
        cnt += c
        final_array.append(curr)
    if len(final_array) == 1:
        return final_array[0], cnt
    return merge(final_array, cnt)


def count_inv(array):
    array = split_array(array)
    return merge(array)[1]






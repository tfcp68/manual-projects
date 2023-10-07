
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


def sort_arrays(arrays):
    first, second = arrays
    i = j = 0
    new_array = []
    while i < len(first) and j < len(second):
        if first[i] < second[j]:
            new_array.append(first[i])
            i += 1
        else:
            new_array.append(second[j])
            j += 1
    if i < len(first) or j < len(second):
        new_array += first[i:len(first)]
        new_array += second[j:len(second)]
    return new_array


def merge(array):
    final_array = []
    if len(array) % 2 > 0:
        array.append([])
    for i in range(0, len(array)-1, 2):
        curr = sort_arrays([array[i], array[i + 1]])
        final_array.append(curr)
    if len(final_array) == 1:
        return final_array[0]
    return merge(final_array)


def merge_sort(array):
    array = split_array(array)
    return merge(array)





def insert_sort(array: list, data_length: int):

	for number_index in range(0, data_length):
	
		current_index = number_index
	
		while current_index > 0 and array[current_index] < array[current_index - 1]:
			tmp = array[current_index - 1]
			array[current_index - 1] = array[current_index]
			array[current_index] = tmp
			current_index -= 1

	return array
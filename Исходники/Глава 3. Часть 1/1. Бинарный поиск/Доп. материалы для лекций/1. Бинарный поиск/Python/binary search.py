def binarySearch(array: list, data: int):
	left = 0
	right = len(array) - 1
	
	while left <= right:
		mid = (left + right) // 2
	
		if array[mid] == data:
			return mid
	
		elif array[mid] < data:
			left = mid + 1
	
		elif array[mid] > data:
			right = mid - 1
	
	return None
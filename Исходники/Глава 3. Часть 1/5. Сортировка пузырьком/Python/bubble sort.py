def bubble_sort(A: list):
    for i in range(len(A) - 1):
        for j in range(len(A) - 1):
	        if A[j] > A[j + 1]:
		        A[j], A[j + 1] = A[j + 1], A[j]
    return A
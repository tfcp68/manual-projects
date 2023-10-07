from math import log2, floor

def sparse_table(A: list):
	LEN = len(A)
	LOG = floor(log2(LEN))
	ST = []
	for i in range(0, LOG+1):
		ST.append([])
	ST[0] = A
	
	for i in range(1, LOG+1):
		j = 0
		while ((j + (1 << i)) <= LEN):
			ST[i].append(min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]))
			j+=1
	return ST


def find_min(L, R, ST):
	i = floor(log2(R - L + 1))
	return min(ST[i][L], ST[i][R - (1 << i) + 1])
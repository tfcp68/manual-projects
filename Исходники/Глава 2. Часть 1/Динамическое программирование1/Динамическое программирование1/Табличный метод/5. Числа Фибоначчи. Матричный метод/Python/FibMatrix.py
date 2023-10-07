class FibMatrix:

    def __init__(self, n):
        self.n = n

    def fib_matrix(self):
        matrix = [[1 for _ in range(2)] for _ in range(2)]
        matrix[1][1] = 0
        if self.n < 0:
            return -1
        if self.n == 0:
            return 0
        if self.n == 1:
            return 1
        bin_matrix = self.bin_pow_matrix(matrix, self.n - 1)
        fib = bin_matrix[0][0]
        return fib

    def bin_pow_matrix(self, matrix, n):
        if n == 1:
            return matrix

        if n % 2 != 0:
            temp_matrix = self.bin_pow_matrix(matrix, n - 1)
            return self.prod_matrix(temp_matrix, matrix)

        if n % 2 == 0:
            temp_matrix = self.bin_pow_matrix(matrix, n // 2)

            return self.prod_matrix(temp_matrix, temp_matrix)

    def prod_matrix(self, a, b):
        matrix_prod = [[0 for _ in range(2)] for _ in range(2)]
        for i in range(2):
            for j in range(2):
                for r in range(2):
                    matrix_prod[i][j] += a[i][r] * b[r][j]

        return matrix_prod
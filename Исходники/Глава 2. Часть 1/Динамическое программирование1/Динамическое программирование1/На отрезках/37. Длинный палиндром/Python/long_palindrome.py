def long_palindrome(str_: str):
    n = len(str_)
    p = [[0] * n for _ in range(n)]
    for i in range(n):
        p[i][i] = 1
    for len_ in range(1, n):
        for i in range(0, n - len_):
            j = i + len_
            if str_[i] == str_[j]:
                p[i][j] = p[i + 1][j - 1] + 2
            else:
                p[i][j] = max(p[i + 1][j], p[i][j - 1])
    return p[0][n - 1]


class Long_Palindrome:

    def __init__(self, str_):
        self.str_ = str_

    def solve(self):
        count, a = self.long_palindrome_memory()
        n = len(self.str_)
        return self.print_palindrome(0, n - 1, a), count

    def long_palindrome_memory(self):
        n = len(self.str_)
        p = [[0] * n for _ in range(n)]
        memory = [[0] * n for _ in range(n)]
        for i in range(n):
            p[i][i] = 1
        for len_ in range(1, n):
            for i in range(0, n - len_):
                j = i + len_
                if self.str_[i] == self.str_[j]:
                    p[i][j] = p[i + 1][j - 1] + 2
                else:
                    p[i][j] = max(p[i + 1][j], p[i][j - 1])
                    if p[i][j] == p[i + 1][j]:
                        memory[i][j] = 1
                    else:
                        memory[i][j] = 2
        return p[0][n - 1], memory

    def print_palindrome(self, i, j, memory):
        arr = []
        if i > j:
            return arr
        if i == j:
            return [self.str_[i]]
        if memory[i][j] == 0:
            arr += [self.str_[i]]
            arr += self.print_palindrome(i + 1, j - 1, memory)
            arr += [self.str_[j]]
        elif memory[i][j] == 1:
            arr = self.print_palindrome(i + 1, j, memory)
        else:
            arr = self.print_palindrome(i, j - 1, memory)
        return arr


# https://codeforces.com/problemset/problem/1741/D

def split_p(p):
    if len(p) <= 2:
        return [p]
    first, second = p[:len(p)//2], p[len(p)//2:]
    return split_p(first) + split_p(second)


def sort_p(p, cnt):
    if len(p) <= 1:
        return p[0], cnt
    new_p = []
    for i in range(0, len(p) - 1, 2):
        if p[i][0] > p[i + 1][0]:
            new_p.append(p[i + 1] + p[i])
            cnt += 1
        else:
            new_p.append(p[i] + p[i + 1])
    return sort_p(new_p, cnt)


def solve():
    m = int(input())
    p = list(map(int, input().split()))
    if p == list(sorted(p)):
        print(0)
        return

    p = split_p(p)
    cnt = 0
    for i in range(0, len(p)):
        if p[i][0] > p[i][1]:
            p[i] = [p[i][1], p[i][0]]
            cnt += 1

    new_p, cnt = sort_p(p, cnt)
    if new_p == list(sorted(new_p)):
        print(cnt)
    else:
        print(-1)
    return


def main():
    t = int(input())
    for _ in range(t):
        solve()


main()

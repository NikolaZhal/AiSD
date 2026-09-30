import sys


def solve():
    n = int(sys.stdin.readline())
    if n == 1:
        print(1)
        return

    A = [1, 2]
    for k in range(3, n + 1):
        mid = (1 + k) // 2
        pos = mid - 1  # 0-индексация
        r = A[pos]
        A[pos] = k
        A.append(r)

    print(" ".join(map(str, A)))


solve()

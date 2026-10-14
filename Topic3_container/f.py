from collections import deque
import sys


def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    k = int(data[1])
    arr = [int(data[i + 2]) for i in range(n)]

    dq = deque()
    result = []

    for i in range(n):
        while dq and dq[0] < i - k + 1:
            dq.popleft()

        while dq and arr[dq[-1]] > arr[i]:
            dq.pop()

        dq.append(i)

        if i >= k - 1:
            result.append(arr[dq[0]])

    for min_val in result:
        print(min_val)


if __name__ == "__main__":
    main()

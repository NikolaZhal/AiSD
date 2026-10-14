from collections import deque
import sys


def main():
    input = sys.stdin.readline

    n = int(input())

    front = deque()
    back = deque()

    result = []

    for _ in range(n):
        query = input().split()

        if query[0] == "+":
            i = int(query[1])
            back.append(i)

            if len(front) < len(back):
                front.append(back.popleft())

        elif query[0] == "*":
            i = int(query[1])

            if len(front) == len(back):
                front.append(i)
            else:
                back.appendleft(i)

        elif query[0] == "-":
            result.append(front.popleft())

            if len(front) < len(back):
                front.append(back.popleft())

    print("\n".join(map(str, result)))


if __name__ == "__main__":
    main()

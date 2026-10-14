def can_sort_wagons(wagons):
    """Проверяет, можно ли отсортировать вагоны с помощью тупика-стека."""
    stack = []
    expected = 1

    for wagon in wagons:
        stack.append(wagon)

        while stack and stack[-1] == expected:
            stack.pop()
            expected += 1

    return len(stack) == 0


def main():
    n = int(input())
    wagons = list(map(int, input().split()))

    if can_sort_wagons(wagons):
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()

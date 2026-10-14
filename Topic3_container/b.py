def is_correct_bracket_sequence(s: str) -> bool:
    """Проверяет, является ли скобочная последовательность правильной."""
    stack = []
    matching = {")": "(", "]": "[", "}": "{"}

    for char in s:
        if char in "([{":
            stack.append(char)
        elif char in ")]}":
            if not stack:
                return False
            if stack[-1] != matching[char]:
                return False
            stack.pop()

    return len(stack) == 0


def main():
    s = input().strip()
    if is_correct_bracket_sequence(s):
        print("yes")
    else:
        print("no")


if __name__ == "__main__":
    main()

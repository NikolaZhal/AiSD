def evaluate_postfix(expression: str) -> int:
    """Вычисляет значение выражения в постфиксной (обратной польской) записи."""
    stack = []
    tokens = expression.split()

    for token in tokens:
        if token in "+-*":
            b = stack.pop()
            a = stack.pop()

            if token == "+":
                result = a + b
            elif token == "-":
                result = a - b
            elif token == "*":
                result = a * b

            stack.append(result)
        else:
            stack.append(int(token))

    return stack[0]


def main():
    expression = input()
    print(evaluate_postfix(expression))


if __name__ == "__main__":
    main()

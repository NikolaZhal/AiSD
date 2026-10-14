import sys


class Stack:
    """Стек — структура данных LIFO (последним пришёл — первым ушёл)."""

    def __init__(self):
        self._items = []

    def push(self, value):
        """Добавить элемент на вершину стека."""
        self._items.append(value)

    def pop(self):
        """Удалить и вернуть последний элемент (или None, если стек пуст)."""
        if self.is_empty():
            return None
        return self._items.pop()

    def back(self):
        """Вернуть последний элемент, не удаляя его (или None, если стек пуст)."""
        if self.is_empty():
            return None
        return self._items[-1]

    def size(self):
        """Количество элементов в стеке."""
        return len(self._items)

    def clear(self):
        """Очистить стек."""
        self._items.clear()

    def is_empty(self):
        return len(self._items) == 0


def main():
    stack = Stack()
    output = []

    for line in sys.stdin:
        parts = line.split()
        if not parts:
            continue

        command = parts[0]

        if command == "push":
            value = parts[1] if len(parts) > 1 else "0"
            stack.push(value)
            output.append("ok")

        elif command == "pop":
            if stack.is_empty():
                output.append("error")
            else:
                output.append(str(stack.pop()))

        elif command == "back":
            if stack.is_empty():
                output.append("error")
            else:
                output.append(str(stack.back()))

        elif command == "size":
            output.append(str(stack.size()))

        elif command == "clear":
            stack.clear()
            output.append("ok")

        elif command == "exit":
            output.append("bye")
            break

    if output:
        sys.stdout.write("\n".join(output) + "\n")


if __name__ == "__main__":
    main()

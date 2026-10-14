import sys
from collections import deque


class Deque:
    """Дек — двунаправленная очередь, позволяющая добавлять и удалять элементы с обоих концов."""

    def __init__(self):
        self._items = deque()

    def push_front(self, value):
        """Добавить элемент в начало дека."""
        self._items.appendleft(value)

    def push_back(self, value):
        """Добавить элемент в конец дека."""
        self._items.append(value)

    def pop_front(self):
        """Извлечь и вернуть первый элемент (или None, если дек пуст)."""
        if self.is_empty():
            return None
        return self._items.popleft()

    def pop_back(self):
        """Извлечь и вернуть последний элемент (или None, если дек пуст)."""
        if self.is_empty():
            return None
        return self._items.pop()

    def front(self):
        """Вернуть первый элемент, не удаляя его (или None, если дек пуст)."""
        if self.is_empty():
            return None
        return self._items[0]

    def back(self):
        """Вернуть последний элемент, не удаляя его (или None, если дек пуст)."""
        if self.is_empty():
            return None
        return self._items[-1]

    def size(self):
        """Количество элементов в деке."""
        return len(self._items)

    def clear(self):
        """Очистить дек."""
        self._items.clear()

    def is_empty(self):
        """Проверка, пуст ли дек."""
        return len(self._items) == 0


def main():
    deque_obj = Deque()
    output = []

    for line in sys.stdin:
        parts = line.split()
        if not parts:
            continue

        command = parts[0]

        if command == "push_front":
            value = parts[1] if len(parts) > 1 else "0"
            deque_obj.push_front(value)
            output.append("ok")

        elif command == "push_back":
            value = parts[1] if len(parts) > 1 else "0"
            deque_obj.push_back(value)
            output.append("ok")

        elif command == "pop_front":
            if deque_obj.is_empty():
                output.append("error")
            else:
                output.append(str(deque_obj.pop_front()))

        elif command == "pop_back":
            if deque_obj.is_empty():
                output.append("error")
            else:
                output.append(str(deque_obj.pop_back()))

        elif command == "front":
            if deque_obj.is_empty():
                output.append("error")
            else:
                output.append(str(deque_obj.front()))

        elif command == "back":
            if deque_obj.is_empty():
                output.append("error")
            else:
                output.append(str(deque_obj.back()))

        elif command == "size":
            output.append(str(deque_obj.size()))

        elif command == "clear":
            deque_obj.clear()
            output.append("ok")

        elif command == "exit":
            output.append("bye")
            break

    if output:
        sys.stdout.write("\n".join(output) + "\n")


if __name__ == "__main__":
    main()

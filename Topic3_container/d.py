import sys
from collections import deque


class Queue:
    """Очередь — структура данных FIFO (первым пришёл — первым ушёл)."""

    def __init__(self):
        self._items = deque()

    def push(self, value):
        """Добавить элемент в конец очереди."""
        self._items.append(value)

    def pop(self):
        """Удалить и вернуть первый элемент (или None, если очередь пуста)."""
        if self.is_empty():
            return None
        return self._items.popleft()

    def front(self):
        """Вернуть первый элемент, не удаляя его (или None, если очередь пуста)."""
        if self.is_empty():
            return None
        return self._items[0]

    def size(self):
        """Количество элементов в очереди."""
        return len(self._items)

    def clear(self):
        """Очистить очередь."""
        self._items.clear()

    def is_empty(self):
        return len(self._items) == 0


def main():
    queue = Queue()
    output = []

    for line in sys.stdin:
        parts = line.split()
        if not parts:
            continue

        command = parts[0]

        if command == "push":
            value = parts[1] if len(parts) > 1 else "0"
            queue.push(value)
            output.append("ok")

        elif command == "pop":
            if queue.is_empty():
                output.append("error")
            else:
                output.append(str(queue.pop()))

        elif command == "front":
            if queue.is_empty():
                output.append("error")
            else:
                output.append(str(queue.front()))

        elif command == "size":
            output.append(str(queue.size()))

        elif command == "clear":
            queue.clear()
            output.append("ok")

        elif command == "exit":
            output.append("bye")
            break

    if output:
        sys.stdout.write("\n".join(output) + "\n")


if __name__ == "__main__":
    main()

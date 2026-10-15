from functools import cmp_to_key
from pprint import pprint

data = [
    ["Иванов1", 2, 1],
    ["Иванов2", 5, 2],
    ["Иванов3", 5, 2],
    ["Иванов4", 6, 1],
    ["Абрамов", 3, 2],
    ["Бакулев", 1, 8],
    ["Васильева", 9, 4],
    ["Геннадьев", 4, 3],
    ["Дмитриенко", 3, 5],
]


def comparator(x, y):
    if x[1] + x[2] > y[1] + y[2]:
        return -1  # должны возвращать 1, но сортировка по убыванию
    elif x[1] + x[2] < y[1] + y[2]:
        return 1
    if x[0] > y[0]:
        return 1
    return -1


pprint(sorted(data, key=cmp_to_key(comparator)))

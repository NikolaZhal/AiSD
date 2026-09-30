import sys

def solve():
    # Читаем все входные данные
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    a = int(input_data[1])
    b = int(input_data[2])
    w = int(input_data[3])
    h = int(input_data[4])

    # Функция проверки: можно ли разместить n модулей с толщиной защиты d
    def check(d):
        # Ориентация 1: a+2d по ширине, b+2d по высоте
        wa = a + 2 * d
        hb = b + 2 * d
        if wa <= w and hb <= h:
            if (w // wa) * (h // hb) >= n:
                return True
        
        # Ориентация 2: b+2d по ширине, a+2d по высоте (поворот на 90 градусов)
        wb = b + 2 * d
        ha = a + 2 * d
        if wb <= w and ha <= h:
            if (w // wb) * (h // ha) >= n:
                return True
                
        return False

    # Бинарный поиск по толщине защиты
    left = 0
    right = 10**18  # Максимально возможная толщина
    ans = 0

    while left <= right:
        mid = (left + right) // 2
        if check(mid):
            ans = mid
            left = mid + 1  # Пробуем увеличить толщину
        else:
            right = mid - 1 # Уменьшаем толщину

    print(ans)

if __name__ == '__main__':
    solve()
import sys


def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    n = int(input_data[0])
    a = int(input_data[1])
    b = int(input_data[2])
    w = int(input_data[3])
    h = int(input_data[4])

    def check(d):
        wa = a + 2 * d
        hb = b + 2 * d
        if wa <= w and hb <= h:
            if (w // wa) * (h // hb) >= n:
                return True

        wb = b + 2 * d
        ha = a + 2 * d
        if wb <= w and ha <= h:
            if (w // wb) * (h // ha) >= n:
                return True

        return False

    left = 0
    right = 10**18

    while right - left > 1:
        mid = (left + right) // 2
        if check(mid):
            left = mid
        else:
            right = mid

    print(left)


if __name__ == "__main__":
    solve()

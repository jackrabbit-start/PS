a, b, c = map(int, input().split())


def divide_conquer(n):
    if n == 1:
        return a % c

    tmp = divide_conquer(n // 2)

    if n % 2 == 1:
        return tmp * tmp % c * a % c
    else:
        return tmp * tmp % c


print(divide_conquer(b) % c)

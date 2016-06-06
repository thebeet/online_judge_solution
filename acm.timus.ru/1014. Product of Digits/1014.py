n = int(input())

if n == 0:
    print(10)
elif n == 1:
    print(1)
else:
    divs = [0 for x in range(10)]
    for i in range(9, 1, -1):
        while n % i == 0:
            n = n // i
            divs[i] += 1
    if n > 1:
        print(-1)
    else:
        for i in range(2, 10):
            for j in range(0, divs[i]):
                print(i, end='')

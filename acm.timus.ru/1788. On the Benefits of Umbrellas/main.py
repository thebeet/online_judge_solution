n, m = input().split()
n, m = int(n), int(m)
girl = [int(i) for i in input().split()]
girl.sort()
girl.reverse()
boy = [int(i) for i in input().split()]
boy.sort()
boy.reverse()
result = 1000000000
for i in range(min(n, m) + 1):
    result = min(result, sum(girl[i:]) + i * sum(boy[i:]))

print(result)


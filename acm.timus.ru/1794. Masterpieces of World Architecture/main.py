n = input()
n = int(n)
s = [int(i) for i in input().split()]
p = [0 for i in range(n)]
for i in range(n):
    p[i - s[i] + 1] += 1

maxi = 0
for i in range(n):
    if p[maxi] < p[i]:
        maxi = i
print(maxi + 1)

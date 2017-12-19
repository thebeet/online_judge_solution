n, k = input().split()
n, k = int(n), int(k)
result = [0 for i in range(n)]
dk = 0
for i in range(k):
    result[i] = dk
    if dk > 0:
        dk = -dk
    else:
        dk = -dk
        dk = dk + 1
for i in range(n):
    print(result[i], end=" ")
print()

m = {}
s = [0 for i in range(n + 1)]
s[0] = result[0]
for i in range(n):
    s[i + 1] = s[i] + result[i]

for i in range(n):
    for j in range(i + 1, n + 1):
        m[s[j] - s[i]] = True

ans = 0
for i in range(-10000, 10000):
    if i in m:
        ans += 1

print(ans)




s = input()
for i in range(1, 100000):
    si = str(i)
    if not si in s:
        print(si)
        break


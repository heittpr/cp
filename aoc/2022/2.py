import sys

cur = 0
ans = []

for line in sys.stdin:
    if line != '\n':
        cur += int(line)
    else:
        ans.append(cur)
        cur = 0

ans = sorted(ans, reverse=True)
print(sum(ans[:3]))

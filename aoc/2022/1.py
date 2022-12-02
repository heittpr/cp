import sys

cur = 0
ans = 0

for line in sys.stdin:
    if line != '\n':
        cur += int(line)
    else:
        ans = max(ans, cur)
        cur = 0

print(ans)

import sys
from itertools import combinations

for line in sys.stdin:
    n, m = map(int, line.split())
    if (n == 0 and m ==0): 
        break
    items = [chr(i) for i in range(97, 97 + n)]
    for combo in combinations(items, m):
        print(''.join(combo))

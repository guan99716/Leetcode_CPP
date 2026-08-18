from itertools import combinations

items = ['A', 'B', 'C']
n = len(items)
for r in range(n+1):
    for combo in combinations(items, r):
            print(list(combo))

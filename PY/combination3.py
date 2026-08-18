output = []
items = ['A', 'B', 'C']
n = len(items)
for mask in range(1 << n):
    subset = [items[i] for i in range(n) if mask & (1 << i)]
    output.append(subset)
output.sort(key=len) 
for combo in output:
    if combo:
        print(''.join(combo))